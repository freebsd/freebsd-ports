# ports collection makefile for:	hylafax
# Version required:	v4.0pl2
# Date created:		19 Apr 1997
# Whom:			ports@freebsd.org
#
# $Id: Makefile,v 1.20 1998/11/25 09:01:16 asami Exp $
#

DISTNAME=	hylafax-v4.0pl2
PKGNAME=	hylafax-4.0.2
CATEGORIES=	comms
MASTER_SITES=	ftp://ftp.sgi.com/sgi/fax/source/ \
		ftp://ftp.leo.org/pub/comp/os/unix/networking/fax/hylafax/source/ \
		ftp://ftp.sisis.de/pub/hylafax/source/
EXTRACT_SUFX=	-tar.gz

MAINTAINER=	ports@freebsd.org

BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash2 \
		${PREFIX}/lib/afm/Courier:${PORTSDIR}/print/afm
# no dependency on ghostscript because we don't know which
# version the user prefers
RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash2
LIB_DEPENDS=	tiff.4:${PORTSDIR}/graphics/tiff34 \
		jpeg.9:${PORTSDIR}/graphics/jpeg

USE_GMAKE=	yes
CONFIGURE_ARGS=	--with-INSTALL="" \
		--with-MAKE=gmake --with-CC=/usr/bin/cc \
		--with-LIBTIFF="-L${PREFIX}/lib -ltiff -ljpeg" \
		--with-TIFFINC="${PREFIX}/include"
HAS_CONFIGURE=	yes
MAN1=	hylafax.1 faxalter.1 faxcover.1 faxmail.1 faxrm.1 faxstat.1 sendfax.1 \
	sendpage.1 sgi2fax.1 textfmt.1
MAN5=	pagesizes.5f typerules.5f \
	hylafax.5f cid.5f config.5f destctrls.5f dialrules.5f hosts.5f \
	info.5f log.5f pagermap.5f recvq.5f sendq.5f shutdown.5f status.5f \
	tsi.5f xferlog.5f
MAN8=	cqtest.8c choptest.8c dialtest.8c faxabort.8c faxaddmodem.8c \
	faxanswer.8c faxconfig.8c faxmodem.8c faxstate.8c faxcron.8c \
	faxgetty.8c faxinfo.8c faxq.8c faxqclean.8c faxquit.8c faxrcvd.8c \
	faxsend.8c faxsetup.8c faxwatch.8c hfaxd.8c mkcover.8c notify.8c \
	pagesend.8c pollrcvd.8c ps2fax.8c recvstats.8c tagtest.8c tiff2fax.8c \
	tiffcheck.8c tsitest.8c wedged.8c xferstats.8c

SUID_EXES= 	${PREFIX}/sbin/faxgetty ${PREFIX}/sbin/faxq \
		${PREFIX}/bin/faxrm ${PREFIX}/bin/faxalter

post-install:
	chown uucp ${SUID_EXES}
	chmod 4555 ${SUID_EXES}
	@if [ ! -f ${PREFIX}/etc/rc.d/hylafax.sh.sample ]; then	\
		cp ${FILESDIR}/hylafax.sh.sample ${PREFIX}/etc/rc.d;	\
	fi
	${CAT} ${PKGDIR}/MESSAGE

.include <bsd.port.mk>
