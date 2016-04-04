# Created by: Jason Helfman <jgh@FreeBSD.org>
# $FreeBSD$

PORTNAME=	spice-protocol
PORTVERSION=	0.12.10
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.spice-space.org/download/releases/

MAINTAINER=	novel@FreeBSD.org
COMMENT=	Simple Protocol for Independent Computing Environments

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six

GNU_CONFIGURE=	yes
USES=		gmake pathfix pkgconfig python tar:bzip2

post-patch:
	@${REINPLACE_CMD} -e 's|(libdir)/spice-protocol|(datadir)/spice-protocol/|' \
		${WRKSRC}/Makefile.in ${WRKSRC}/python_modules/Makefile.in

post-install:
	@${PYTHON_CMD} -m compileall -d ${DATADIR} ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
