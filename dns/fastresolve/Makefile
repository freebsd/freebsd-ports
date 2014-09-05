# Created by: verm@drunkmonk.net
# $FreeBSD$

PORTNAME=	fastresolve
PORTVERSION=	2.10
PORTREVISION=	5
CATEGORIES=	dns
MASTER_SITES=	http://www.djmnet.org/sw/dist/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Programs that process web logs to get DNS and domain ownership info

LIB_DEPENDS=	libadns.so:${PORTSDIR}/dns/adns
RUN_DEPENDS=	p5-BerkeleyDB>=0:${PORTSDIR}/databases/p5-BerkeleyDB

LICENSE=	GPLv2

OPTIONS_DEFINE=	DOCS

USES=		perl5 tar:bzip2
USE_BDB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	PERL=${PERL} \
		djm_cv_lib_db_Dbopen=yes
LDFLAGS+=	-L${LOCALBASE}/lib -L${BDB_LIB_DIR}
CXXFLAGS+=	-I${LOCALBASE}/include -I${BDB_INCLUDE_DIR}

post-patch:
	@${REINPLACE_CMD} -e 's/-ldb"/-l${BDB_LIB_CXX_NAME}"/g' ${WRKSRC}/configure

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in AUTHORS COPYING ChangeLog INSTALL NEWS README
	@${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor
	@${INSTALL_DATA} ${WRKSRC}/doc/TODO ${STAGEDIR}${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/timings ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
