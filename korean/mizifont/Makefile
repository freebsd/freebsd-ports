# New ports collection makefile for:	mizifonts
# Date created:		16 Mar 1998
# Whom:			CHOI Junho <cjh@kr.freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	mizifonts
PORTVERSION=	1.1
PORTREVISION=	3
CATEGORIES=	korean x11-fonts
MASTER_SITES=	ftp://ftp.mizi.co.kr/pub/hanIM/
DISTNAME=	xfntmizi-1.1-2.noarch
EXTRACT_SUFX=	.rpm

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Mizi Research's Korean X11 Font(ksc5601.1987-[01] encoding)

EXTRACT_DEPENDS=rpm2cpio:${PORTSDIR}/archivers/rpm

RUN_DEPENDS=	bdftopcf:${PORTSDIR}/x11-fonts/bdftopcf \
		mkfontdir:${PORTSDIR}/x11-fonts/mkfontdir
RUN_DEPENDENS=	mkfontdir:${PORTSDIR}/x11-fonts/mkfontdir \
		mkfontscale:${PORTSDIR}/x11-fonts/mkfontscale

NO_WRKSUBDIR=	yes

RPM2CPIO=	rpm2cpio
CPIO_OPT=	-i --make-directories
UNCOMPRESS=	/usr/bin/uncompress
FONTS=		mzgt16e.pcf mzgt16h.pcf mzgt16h1.pcf mzmj16e.pcf mzmj16h.pcf \
		mzpg16e.pcf mzpg16h.pcf mzsm16e.pcf  mzsm16h.pcf

do-extract:
	@${RM} -rf ${WRKDIR} && \
	${MKDIR} ${WRKDIR} && \
	cd ${WRKDIR} && \
	${RPM2CPIO} ${_DISTDIR}/${DISTFILES} | ${CPIO} ${CPIO_OPT} && \
	${MV} ${WRKDIR}/usr/lib/X11/fonts/misc/* .

do-build:
	@cd ${WRKDIR}; \
	for i in ${FONTS}; do \
		${UNCOMPRESS} -c $$i.Z | ${GZIP_CMD} -c > $$i.gz; \
	done

do-install:
	@${MKDIR} ${PREFIX}/lib/X11/fonts/local
	for i in ${WRKDIR}/*.gz; do \
		${INSTALL_DATA} $$i ${PREFIX}/lib/X11/fonts/local/; \
	done
	cd ${PREFIX}/lib/X11/fonts/local/ ; ${LOCALBASE}/bin/mkfontdir

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
