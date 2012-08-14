# New ports collection makefile for:   tqsllib
# Date created:                10th August 2012
# Whom:                        Diane Bruce <db@db.net>
#
# $FreeBSD$
#

PORTNAME=	tqsllib
PORTVERSION=	2.2
CATEGORIES=	comms hamradio
MASTER_SITES=	SF/trustedqsl/tqsllib/V2.2/

MAINTAINER=	db@FreeBSD.org
COMMENT=	Amateur Radio Station electronic trusted logbook libraries

LIB_DEPENDS=	expat:${PORTSDIR}/textproc/expat2

GNU_CONFIGURE=	YES
USE_LDCONFIG=	YES
USE_OPENSSL=	YES
CONFIGURE_ARGS+=	"CXXFLAGS=${CXXFLAGS} -fpermissive" --enable-docs=no \
				--with-openssl=${OPENSSLBASE}

.include <bsd.port.pre.mk>

post-configure:
	@${REINPLACE_CMD} -e 's|-lcrypto|${OPENSSLLIB}/libcrypto.so|' \
		${WRKSRC}/Makefile

pre-install:
	(cd ${WRKSRC}; \
		make converter;make gen_crq; \
		make load_cert;make station_loc)

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/converter ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/gen_crq ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/load_cert ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/station_loc ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/tqsllib
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${PREFIX}/share/doc/tqsllib
	${INSTALL_DATA} ${WRKSRC}/ChangeLog ${PREFIX}/share/doc/tqsllib
.endif

.include <bsd.port.post.mk>
