# Ceeated by: Jim Mock <jim@FreeBSD.org>
# $FreeBSD$

PORTNAME=	corewars
PORTVERSION=	0.9.13
PORTREVISION=	4
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}%20%28stable%2C%20tar.gz%29/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simulation game where the goal is to crash each other's programs

BUILD_DEPENDS=	${LOCALBASE}/lib/libargp.a:${PORTSDIR}/devel/argp-standalone

USE_GNOME=	gtk12

GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.if defined(.PARSEDIR)
USE_GMAKE=	yes
.endif

MAN6=		corewars.6
MLINKS=		corewars.6 corewars-cmd.6

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
