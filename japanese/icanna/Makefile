PORTNAME=	icanna
PORTVERSION=	0.9.0
CATEGORIES=	japanese
MASTER_SITES=	http://www.ceres.dti.ne.jp/~knak/
DISTNAME=	yc-${YC_VERSION}

MAINTAINER=	t@nakao.org
COMMENT=	Canna connector for yc.el via unix domain socket

YC_VERSION=	4.0.13

PLIST_FILES+=	bin/icanna

do-build:
	${CC} ${CFLAGS} -o ${WRKSRC}/${PORTNAME} ${WRKSRC}/${PORTNAME}.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
