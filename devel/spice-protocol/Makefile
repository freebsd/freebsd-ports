# Created by: Jason Helfman <jgh@FreeBSD.org>
# $FreeBSD$

PORTNAME=	spice-protocol
PORTVERSION=	0.12.10
CATEGORIES=	devel
MASTER_SITES=	http://www.spice-space.org/download/releases/

MAINTAINER=	novel@FreeBSD.org
COMMENT=	Simple Protocol for Independent Computing Environments

LICENSE=	BSD3CLAUSE

GNU_CONFIGURE=	yes
USES=	gmake pathfix pkgconfig tar:bzip2

post-patch:
	@${REINPLACE_CMD} -e 's|(libdir)/spice-protocol|(datadir)/spice-protocol/|' \
		${WRKSRC}/Makefile.in ${WRKSRC}/python_modules/Makefile.in

.include <bsd.port.mk>
