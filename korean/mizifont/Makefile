# New ports collection makefile for:	mizifonts
# Version required:	1.1
# Date created:		16 Mar 1998
# Whom:			CHOI Junho <junker@jazz.snu.ac.kr>
#
# $Id: Makefile,v 1.7 1998/11/18 13:03:40 asami Exp $
#

DISTNAME=	xfntmizi-1.1-2.noarch
PKGNAME=	ko-mizifonts-1.1
CATEGORIES=	korean x11-fonts
MASTER_SITES=	http://www.mizi.co.kr/packages/
EXTRACT_SUFX=	.rpm

MAINTAINER=	junker@jazz.snu.ac.kr

BUILD_DEPENDS=	rpm2cpio:${PORTSDIR}/misc/rpm

NO_CDROM=	"Not a free software, but redistributable on FreeBSD mirrors"

USE_X_PREFIX=	yes
NO_WRKSUBDIR=	yes

RPM2CPIO=	rpm2cpio
CPIO=		/usr/bin/cpio
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
	@mkdir -p ${PREFIX}/lib/X11/fonts/local
	for i in ${WRKDIR}/*.gz; do \
		${INSTALL_DATA} $$i ${PREFIX}/lib/X11/fonts/local/; \
	done
	cd ${PREFIX}/lib/X11/fonts/local/ ; mkfontdir

post-install:
	@cat ${PKGDIR}/MESSAGE

.include <bsd.port.mk>
