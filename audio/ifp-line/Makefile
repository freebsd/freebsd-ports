# Created by: riggs
# $FreeBSD$

PORTNAME=	ifp-line
PORTVERSION=	0.3
CATEGORIES=	audio
MASTER_SITES=	SF/ifp-driver/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Command line interface to iRiver music players

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf iconv
GNU_CONFIGURE=	yes
MAKE_JOBS_UNSAFE=	yes

LDFLAGS+=	-lusb

PLIST_FILES=	bin/ifp man/man1/ifp.1.gz
PORTDOCS=	NEWS README TIPS nonroot.sh

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e \
		'/LIBUSB/s|ERROR|WARN|' ${WRKSRC}/configure.ac

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ifp ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/ifp.1 ${STAGEDIR}${MANPREFIX}/man/man1

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
