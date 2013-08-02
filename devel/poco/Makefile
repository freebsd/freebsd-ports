# Created by: wes@FreeBSD.org
# $FreeBSD$

PORTNAME=	poco
PORTVERSION=	1.4.3
CATEGORIES=	devel net
MASTER_SITES=	SF/${PORTNAME}/sources/${PORTNAME}-${PORTVERSION}
DISTNAME=	${PORTNAME}-${PORTVERSION}p1

MAINTAINER=	wes@FreeBSD.org
COMMENT=	C++ Portable Components library

CONFLICTS=	poco-ssl-[0-9]*

OPTIONS_DEFINE=	TEST SAMPLES
SAMPLES_DESC=	Build sample programs

CONFIGURE_ARGS= --config=FreeBSD
USES=		gmake

.include <bsd.port.options.mk>

.if ! ${PORT_OPTIONS:MTEST}
CONFIGURE_ARGS+= --no-tests
.endif

.if ! ${PORT_OPTIONS:MSAMPLES}
CONFIGURE_ARGS+= --no-samples
.endif

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e "s/ =/ ?=/g" ${WRKSRC}/build/config/FreeBSD

.include <bsd.port.mk>
