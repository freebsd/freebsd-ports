# Created by: Jason Bacon <jwbacon@tds.net>
# $FreeBSD$

PORTNAME=	plinkseq
PORTVERSION=	0.08
PORTREVISION=	1
CATEGORIES=	biology science
MASTER_SITES=	http://atgu.mgh.harvard.edu/${PORTNAME}/dist/version-${PORTVERSION}/

MAINTAINER=	jwbacon@tds.net
COMMENT=	Toolset for working with human genetic variation data

LICENSE=	GPLv2

LIB_DEPENDS=	libprotobuf.so:${PORTSDIR}/devel/protobuf

USE_DOS2UNIX=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-protobuf=${LOCALBASE}

NO_STAGE=	yes
post-patch:
	${REINPLACE_CMD} -e 's|PF_INET|AF_INET|g' ${WRKSRC}/browser/mongoose.c
	${REINPLACE_CMD} -e 's|-ldl||g' \
		${WRKSRC}/browser/Makefile.in \
		${WRKSRC}/client/Makefile.in \
		${WRKSRC}/index/Makefile.in

.include <bsd.port.mk>
