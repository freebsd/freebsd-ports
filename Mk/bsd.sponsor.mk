# These variables are used in Ports framework to define the ways to support
# port maintainers.
#
# SPONSORSHIP_PLATFORMS		- List of ways to endorse the port's maintainer
#				Currently supported values are:
#				BOOSTY
#				CARDANO
#				GITHUB
#				OPENCOLLECTIVE
#				PATREON
#
#				Each platform may have ":upstream" suffix to allow
#				sponsoring project's upstream instead of a
#				downstream maintainer.
#
#				To define an additional platform the following
#				vars should be defined:
# ${plat}_SPONSOR_HANDLE	- Account name or some other handle for the
#				  given platform
# ${plat}_UPSTREAM_SPONSOR_HANDLE	- The same as ${plat}_SPONSOR_HANDLE for
#					  the ":upstream" case.
# ${plat}_SPONSOR_URL		- URL leading to the site that allows to make
#				  to make a donation
#
# Variables listed above may be either put into a port's Makefile directly or
# set automatically based on the MAINTAINER knob value and the data from
# bsd.sponsor.db.mk
#
# An auxiliary "make sponsor" target points the user to appropriate web page.
# An auxiliary "make sponsor-describe" target prints a machine-readable description
# of the sponsorship data.

.if !defined(SPONSORMKINCLUDED)
SPONSORMKINCLUDED=	bsd.sponsor.mk

BOOSTY_SPONSOR_URL=	https://boosty.to/%%HANDLE%%
CARDANO_SPONSOR_URL=	https://cexplorer.io/address/%%HANDLE%%
GITHUB_SPONSOR_URL=	https://github.com/sponsors/%%HANDLE%%
OPENCOLLECTIVE_SPONSOR_URL=	https://opencollective.com/%%HANDLE%%
PATREON_SPONSOR_URL=	https://www.patreon.com/%%HANDLE%%

GITHUB_SPONSOR_HANDLE?=			${GH_PROJECT}
GITHUB_UPSTREAM_SPONSOR_HANDLE?=	${GH_PROJECT}

.include "${PORTSDIR}/Mk/bsd.sponsor.db.mk"
_MAINTAINER_KEY=	${MAINTAINER:S/@FreeBSD.org/_at_freebsd_org/:S/@freebsd.org/_at_freebsd_org/}
.  if defined(${_MAINTAINER_KEY}_SPONSORSHIP_PLATFORMS)
SPONSORSHIP_PLATFORMS+=	${${_MAINTAINER_KEY}_SPONSORSHIP_PLATFORMS}
.    for plat in ${SPONSORSHIP_PLATFORMS}
.      if defined(${_MAINTAINER_KEY}_${plat}_SPONSOR_HANDLE)
${plat}_SPONSOR_HANDLE=	${${_MAINTAINER_KEY}_${plat}_SPONSOR_HANDLE}
.      endif
.    endfor
.  endif

.  for plat in ${SPONSORSHIP_PLATFORMS}
.    for plat_w_u plat_wo_u in ${plat:S/:upstream/_UPSTREAM/} ${plat:S/:upstream//}
.      if !defined(${plat_w_u}_SPONSOR_HANDLE) || empty(${plat_w_u}_SPONSOR_HANDLE)
.error Missing ${plat_w_u}_SPONSOR_HANDLE value
.      endif
.      if !defined(${plat_wo_u}_SPONSOR_URL) || empty(${plat_wo_u}_SPONSOR_URL)
.error Missing ${plat_wo_u}_SPONSOR_URL value
.      endif
.    endfor
.  endfor

SPONSOR_DIALOG=	${DIALOG} --backtitle "Sponsorship options" \
		--menu "Support options for ${PORTNAME}" 0 0 0

.  for plat in ${SPONSORSHIP_PLATFORMS}
.    for plat_w_u plat_wo_u in ${plat:S/:upstream/_UPSTREAM/} ${plat:S/:upstream//}
SPONSOR_DIALOG_ARGS+=	${plat_w_u} "${${plat_wo_u}_SPONSOR_URL:S/%%HANDLE%%/${${plat_w_u}_SPONSOR_HANDLE}/}"
PKG_NOTE_sponsor+=	${plat_w_u:tl}=${${plat_wo_u}_SPONSOR_URL:S/%%HANDLE%%/${${plat_w_u}_SPONSOR_HANDLE}/}
.    endfor
.  endfor

.  if exists(${LOCALBASE}/bin/xdg-open)
SPONSOR_CMD=	${LOCALBASE}/bin/xdg-open %%URL%%
.  else
SPONSOR_CMD=	${ECHO_CMD} To sponsor the ${PORTNAME} project visit %%URL%%
.  endif

.  if !empty(SPONSORSHIP_PLATFORMS)
PKG_NOTES+=	sponsor

sponsor:
	@(_selected_platform_w_u=$$( { ${SPONSOR_DIALOG} ${SPONSOR_DIALOG_ARGS} 2>&1 >&3; } 3>&2 ) 2>&1 ;\
	_selected_platform_wo_u=$$(${ECHO_CMD} $$_selected_platform_w_u | sed 's/_UPSTREAM//') ;\
	_url=$$(${MAKE} -C ${.CURDIR} -v $${_selected_platform_wo_u}_SPONSOR_URL) ;\
	_handle=$$(${MAKE} -C ${.CURDIR} -v $${_selected_platform_w_u}_SPONSOR_HANDLE) ;\
	_url=$$(${ECHO_CMD} $$_url | sed "s|%%HANDLE%%|$$_handle|") ;\
	`${ECHO_CMD} ${SPONSOR_CMD} | sed "s|%%URL%%|$$_url|"` ;\
	)
.  else
sponsor:
	@${ECHO_CMD} No sponsorship platforms defined for ${PORTNAME} maintainer
	@${FALSE}
.  endif

# The format is
# distribution-name|maintainer|sponsorship_platform|sponsorship_type|sponsorship_url
sponsor-describe: ${SPONSORSHIP_PLATFORMS:tl:S/:upstream/-upstream/:S/^/sponsor-describe-/}
	@${DO_NADA}

.  for plat in ${SPONSORSHIP_PLATFORMS}
.    for plat_w_u plat_wo_u in ${plat:S/:upstream/_UPSTREAM/} ${plat:S/:upstream//}
sponsor-describe-${plat:tl:S/:upstream/-upstream/}:
	@${ECHO_CMD} "${PKGNAME}|${MAINTAINER}|${plat_wo_u}|${"${plat_w_u:M*_UPSTREAM}":?Upstream:Maintainer}|${${plat_wo_u}_SPONSOR_URL:S/%%HANDLE%%/${${plat_w_u}_SPONSOR_HANDLE}/}"
.    endfor
.  endfor

.endif
