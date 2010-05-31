# New ports collection makefile for:	aegis
# Date created:				2007-12-20
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	aegis
PORTVERSION=	4.24
PORTREVISION=	5
CATEGORIES=	devel
MASTER_SITES=	SF

MAINTAINER=	alepulver@FreeBSD.org
COMMENT=	Transaction-based software configuration management system

LIB_DEPENDS=	curl.6:${PORTSDIR}/ftp/curl
RUN_DEPENDS=	tkdiff:${PORTSDIR}/textproc/tkdiff

USE_GETTEXT=	yes
USE_GNOME=	libxml2
USE_PERL5=	yes
USE_TK=		yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-nlsdir="${PREFIX}/share/locale"
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib" \
		WISH="${WISH}"
REINPLACE_ARGS=	-i ''
MAKE_JOBS_UNSAFE=	yes

MAN1=	ae-cvs-ci.1 ae-repo-ci.1 ae-sccs-put.1 ae_c.1 ae_p.1 \
	aeannotate.1 aeb.1 aebisect.1 aebuffy.1 aeca.1 aecd.1 aechown.1 \
	aeclean.1 aeclone.1 aecomp.1 aecomplete.1 aecp.1 aecpu.1 aecvsserver.1 \
	aed.1 aedb.1 aedbu.1 aede.1 aede-policy.1 aedeu.1 aediff.1 \
	aedist.1 aedn.1 aeedit.1 aefa.1 aefind.1 aefinish.1 aefp.1 \
	aeget.1 aegis.1 aegis.cgi.1 aeib.1 aeibu.1 aeifail.1 aeimport.1 \
	aeintegratq.1 aeipass.1 ael.1 aelcf.1 aelic.1 aelock.1 aelpf.1 \
	aels.1 aemakegen.1 aemeasure.1 aemt.1 aemtu.1 aemv.1 aemvu.1 aena.1 \
	aenbr.1 aenbru.1 aenc.1 aencu.1 aend.1 aenf.1 aenfu.1 aeni.1 aenpa.1 \
	aenpr.1 aenrls.1 aenrv.1 aent.1 aentu.1 aepa.1 aepatch.1 \
	aepromptcmd.1 aer.1 aera.1 aerb.1 aerbu.1 aerd.1 aerect.1 \
	aerevml.1 aerfail.1 aeri.1 aerm.1 aermpr.1 aermu.1 aerpa.1 \
	aerpass.1 aerpu.1 aerrv.1 aesub.1 aesubunit.1 aesvt.1 aet.1 \
	aetar.1 aev.1 aexml.1 aexver.1 tkaeca.1 tkaegis.1 tkaenc.1 \
	tkaepa.1 tkaer.1

MAN5=	aecattr.5 aecstate.5 aedir.5 aefattr.5 aefstate.5 aegis.5 \
	aegstate.5 aelock.5 aemetrics.5 aepattr.5 aepconf.5 aepstate.5 \
	aer.5 aerptidx.5 aesub.5 aetest.5 aeuconf.5 aeustate.5

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700000
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-libaegis__wide_output__header.h
.endif

post-patch:
# Avoid "2>/dev/null" redirect in csh (ends up with empty manpath).
	@${REINPLACE_CMD} -Ee 's|(MANPATH_PROG) 2>/dev/null|\1|' \
		${WRKSRC}/configure
# Fix path to Tk interpreter.
	@cd ${WRKSRC}/script && ${REINPLACE_CMD} -e 's|wish |${WISH} |' \
		aebuffy.in aecomp.in aexver.in tkaeca.in tkaegis.in tkaenc.in \
		tkaepa.in tkaer.in xaegis.in
# Import global variable "datadir" inside function (not found otherwise).
	@${REINPLACE_CMD} -e 's|global lib|& datadir|' \
		${WRKSRC}/script/xaegis.in

post-install:
.if !defined(NOPORTDOCS)
. for dir in de en
	${MKDIR} ${DOCSDIR}/${dir}
	cd ${WRKSRC}/lib/${dir} && ${INSTALL_DATA} *.ps *.txt ${DOCSDIR}/${dir}
. endfor
.endif
# Fails to reinstall because keeps track of created directories, so make it
# forget that, by recreating them on each install.
	@${FIND} ${WRKSRC} -type f -name ".*dir" -delete
# Information.
	@${ECHO_CMD}; ${CAT} ${PKGMESSAGE}; ${ECHO_CMD}

.include <bsd.port.post.mk>
