PORTNAME=	emutos
PORTVERSION=	1.4
CATEGORIES=	emulators
MASTER_SITES=	SF

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Free operating system for Atari computers
WWW=		https://sourceforge.net/projects/emutos/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKDIR}/${PORTNAME}-1024k-${PORTVERSION}/doc/license.txt

USES=		zip
NO_BUILD=	yes
ROMS=		1024k 512k 256k 192k
LANGS=		ca cz de es fi fr gr hu it nl no pl ro ru se sg tr uk us
PLIST_FILES=
SRC_FILES=

.for rom in ${ROMS}
DISTFILES+=	${PORTNAME}-${rom}-${PORTVERSION}.zip
.if ${rom} == "1024k"
PLIST_FILES+=	share/${PORTNAME}/etos${rom}.img \
		share/${PORTNAME}/etos${rom}.sym
SRC_FILES+=	${WRKDIR}/${PORTNAME}-${rom}-${PORTVERSION}/etos${rom}.img
SRC_FILES+=	${WRKDIR}/${PORTNAME}-${rom}-${PORTVERSION}/etos${rom}.sym
.else
.for lang in ${LANGS}
PLIST_FILES+=	share/${PORTNAME}/etos${rom:S/k//}${lang}.img
SRC_FILES+=	${WRKDIR}/${PORTNAME}-${rom}-${PORTVERSION}/etos${rom:S/k//}${lang}.img
.endfor
.endif
.endfor

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${SRC_FILES} ${STAGEDIR}${DATADIR}/

.include <bsd.port.mk>
