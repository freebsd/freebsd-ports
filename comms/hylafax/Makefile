# ports collection makefile for:	hylafax
# Version required:	v3.0pl0
# Date created:		16 May 1995
# Whom:			Julian Stacey <jhs@freebsd.org>
# To Replace:		flexfax v2.3beta038special
# Name changed from flexfax to hylafax by author of both: Sam Leffler.

DISTNAME=	hylafax-v3.0pl0
PKGNAME=	hylafax-3.0.0
CATEGORIES+=	comms
KEYWORDS+=	fax
MASTER_SITES=	ftp://ftp.sgi.com/sgi/fax/source/
EXTRACT_SUFX=	-tar.gz
HAS_CONFIGURE=	yes

INSTALL= "sh port/install.sh"
#	By default, FreeBSD make of ports sets INSTALL=install,
#	<bsd.port.mk> says make wont allow variables to be unset.
#	Hylafax ${WRKSRC}/configure needs a special (supplied) install
#	(To quote ${WRKSRC}/config.site:
#	   Beware of changing the INSTALL definition; you *must* have an
# 	   install script that emulates the Silicon Graphics install program!
#	) which it assumes you dont want if you set INSTALL.
#	I would prefer to unset the INSTALL from the FreeBSD ports mechanism,
#	but instead I reset it to what Hylafax wants.
#	As this is still insufficient, See also patches/patch-ad.

MAINTAINER=	jhs@FreeBSD.org

.if !exists(patches/patch-ab)
IS_INTERACTIVE= yes
#	patches/patch-ab makes this BATCH compilable,
#	( If you need interactive config, mv patch-ab patch-ab.mv )
.endif

# EXEC_DEPENDS?=	ghostview:${PORTSDIR}/print/ghostview
#	For viewing faxes, not essential for compiling.

EXEC_DEPENDS+=	gs:${PORTSDIR}/print/ghostscript
#	ghostscript is called by faxcover & sendfax.
#	FreeBSD ports does not come with ghostscript-3 (the license is
#	restrictive), FreeBSD ports comes with ghostscript-2.6.2, which
#	is what I'm currently using. Sam Leffler wrote:
#	Ghostscript versions since 3.12 have had a working tiffg32d
#		driver, but beware of versions before 3.12 that have a
#		tiffg32d driver; those drivers generate invalid 2D-encoded data.

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
	@# If you need interactive config, mv patch-ab patch-ab.mv
.endif

post-install:
	cd ${PREFIX}/bin ; strip \
		fax2ps faxalter faxcover faxmail faxrm faxstat sendfax sendpage
	cd ${PREFIX}/sbin ; strip faxd.recv faxgetty faxq
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

post-clean:
	rm -f \
		fax2ps/fax2ps		\
		faxalter/faxalter	\
		faxcover/faxcover	\
		faxd/faxd		\
		faxgetty/faxgetty	\
		faxmail/faxmail		\
		faxq/faxq		\
		faxrm/faxrm		\
		faxstat/faxstat		\
		recvfax/recvfax		\
		sendfax/sendfax		\
		sendpage/sendpage	\
		sgi2fax/sgi2fax
	@# Sam Leffler (author of Hylafax) has a non standard view of
	@# `make clean': he leaves binaries intact - deliberately !
	@# One cannot use /usr/share/mk/bsd.port.mk re-clean: to invoke
	@# `make clobber' before `make clean'
	@# as it results in	`"rules", ... Could not find Makedepend'

.include <bsd.port.mk>
