# Created by: IWASHITA Yoji <shuna@pop16.odn.ne.jp>
# $FreeBSD$

PORTNAME=	celrw
PORTVERSION=	0.16
CATEGORIES=	japanese
MASTER_SITES=	http://www.nurs.or.jp/~kurati/celrw/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Cellular phone-number read/write tool (in Japan only)

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
MAKE_ARGS=	VERSION="${PORTVERSION}" OPTFLAGS="${CFLAGS}"
ALL_TARGET=	${PORTNAME}

PORTDOCS=	README
PLIST_FILES=	bin/celrw

NO_STAGE=	yes
post-extract:
.for file in config.guess config.sub install.sh
	@${RM} -f ${WRKSRC}/${file}
	@${TOUCH} ${WRKSRC}/${file}
.endfor

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/celrw ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
