# ports collection makefile for:	hylafax
# Version required:	v3.0pl1
# Date created:		16 May 1995
# Whom:			Julian Stacey <jhs@freebsd.org>
# To Replace:		flexfax v2.3beta038special
# Name changed from flexfax to hylafax by author of both: Sam Leffler.
#
# $Id$

DISTNAME=	hylafax-v3.0pl0
PKGNAME=	hylafax-3.0.1
CATEGORIES+=	comms
KEYWORDS+=	fax
MASTER_SITES=	ftp://ftp.sgi.com/sgi/fax/source/
EXTRACT_SUFX=	-tar.gz
HAS_CONFIGURE=	yes

PATCH_SITES=	ftp://ftp.sgi.com/sgi/fax/source/
PATCHFILES=	hylafax-v3.0pl0-patch01.gz 
PATCH_DIST_STRIP=-p1

MAINTAINER=	jhs@FreeBSD.org

.if !exists(patches/patch-ab)
IS_INTERACTIVE= yes
#	patches/patch-ab makes this BATCH compilable,
#	( If you need interactive config, rm patch-ab )
.endif

RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash gs:${PORTSDIR}/print/ghostscript
BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash

# Someone with more time & less space than me can investigate merging these.
# LIB_DEPENDS=		something:${PORTSDIR}/graphics/tiff
# ./libtiff has 2M, & may be duplicates of what is in ${PORTSDIR}/graphics/tiff
# LIB_DEPENDS=          something:${PORTSDIR}/print/afm
# ./afm/ has 536K of fonts, that perhaps could be merged.

FAXCOVER?= /etc/faxcover.ps
#	Default location to check for an optional over-riding host specific
#	customised faxcover that will be installed in these sources,
#	& end up where Hylafax installs all its stuff by default:
#	/var/spool/fax/etc/....
#	Note dont make FAXCOVER use a variable (such as ${PREFIX}),
#	as that wont work in `exists' below.

# ------------------------------------------------------------------------------

# We don't want INSTALL to be passed to configure
do-configure:
	@(cd ${WRKSRC}; CC="${CC}" ac_cv_path_CC="${CC}" CFLAGS="${CFLAGS}" \
	    ./${CONFIGURE_SCRIPT} ${CONFIGURE_ARGS})

post-configure:
.if exists(${FAXCOVER})
	@echo I see you have ${FAXCOVER},
	@echo which I will use to install a system default from.
	@# When I suggested to Sam (in the flexfax mailing list) merging
	@# in the distribution util/cover.templ & faxcover/faxcover.ps
	@# ( as they are virtually identical) Sam said they're for
	@# different things, & wouldn't do it.  I don't know what the
	@# different purposes are, & I Do succesfully use the same file.
	-cd ${WRKSRC} ; mv faxcover/faxcover.ps faxcover/faxcover.ps.mv
	-cd ${WRKSRC} ; mv util/cover.templ util/cover.templ.mv
	-cd ${WRKSRC} ; ln -s ../cover.ps faxcover/faxcover.ps
	-cd ${WRKSRC} ; ln -s ../cover.ps util/cover.templ
	-cd ${WRKSRC} ; ln -s ${FAXCOVER} cover.ps
.endif
.if exists(patches/patch-ab)
	@echo "patches/patch-ab has supressed interactive configuration."
	@# If you need interactive config, rm patch-ab
.endif

post-install:
	cd ${PREFIX}/bin ; strip \
		fax2ps faxalter faxcover faxmail faxrm faxstat sendfax sendpage
	cd ${PREFIX}/sbin ; strip faxd.recv faxgetty faxq
	cd ${PREFIX}/man/man1; \
	    for man in fax2ps.1 faxalter.1 faxcover.1 faxmail.1 \
		faxrm.1 faxstat.1 hylafax.1 sendfax.1 sendpage.1 \
		sgi2fax.1 textfmt.1; do \
	        gzip -9nf $$man; \
	    done
	cd ${PREFIX}/man/man5; \
	    for man in pagesizes.5f typerules.5f cid.5f config.5f \
		destctrls.5f dialrules.5f hosts.5f hylafax.5f info.5f \
		log.5f recvq.5f sendq.5f status.5f tsi.5f xferlog.5f; do \
		gzip -9nf $$man; \
	    done
	cd ${PREFIX}/man/man8; \
	    for man in dialtest.8c faxabort.8c faxaddmodem.8c \
		faxanswer.8c faxcron.8c faxd.recv.8c faxgetty.8c \
		faxq.8c faxquit.8c faxrcvd.8c faxsend.8c mkcover.8c \
		notify.8c pagesend.8c pollrcvd.8c ps2fax.8c \
		recvstats.8c tagtest.8c transcript.8c tsitest.8c \
		xferstats.8c; do \
		gzip -9nf $$man; \
	    done
	@echo "Hylafax by default only does this sete[gu]id 0 stuff:"
	@echo "	-u uucp -m 4755  faxq faxgetty"
	@echo "If you, like I, think it needs more, run 'make suid'"
	@echo "Now consider running	faxaddmodem"

SUID_EXES= 	/usr/local/sbin/faxgetty
SUID_EXES+=	/usr/local/sbin/faxq
SUID_EXES+=	/usr/local/bin/faxrm
SUID_EXES+=	/usr/local/bin/faxalter
suid:
	@# This does too much, & may perhaps cause security loopholes,
	@# but default Hylafax doesnt do enough, eg faxrm wont work,
	@# & even worse, I have received a faxes that then silent failed
	@# to write to recvq.
	@# Only fax modem users who test their hypotheses may change this !
	@# (Imagine losing an important incoming fax, if recvq is unwritable.)
	chown uucp ${SUID_EXES}
	chgrp dialer ${SUID_EXES}
	chmod 6555 ${SUID_EXES}
	find /var/spool/fax -print | xargs chown uucp
	find /var/spool/fax -print | xargs chgrp dialer
	find /var/spool/fax -print | xargs chmod g+w
	find /var/spool/fax -print | xargs chmod g+r
	find /var/spool/fax -type d -print | xargs chmod g+x
	# now remove some x bits that get set by mistake.
	-cd /var/spool/fax ; chmod g-x FIFO* log/* status/* recvq/* sendq/* 
	@echo "Now nonsider doing somethink like this:"
	@echo "	sh"
	@echo "	n=1"
	@echo '	all="ttyd$$n ttyid$$n ttyld$$n cua0$$n cuai0$$n cual0$$n"'
	@echo '	chown uucp $$all; chgrp dialer $$all; chmod 660 $$all'

.include <bsd.port.mk>
