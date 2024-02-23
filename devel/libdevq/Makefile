PORTNAME=	libdevq
PORTVERSION=	0.0.4
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	https://github.com/freebsd/${PORTNAME}/releases/download/${PORTVERSION}/

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Generic Device Query and Monitor interface
WWW=		https://github.com/freebsd/libdevq

LICENSE=	BSD2CLAUSE

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
USES=		autoreconf libtool pathfix tar:xz
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

PATHFIX_MAKEFILEIN=	Makefile.am

OPTIONS_DEFINE=	PROGRAMS
OPTIONS_SUB=	yes
PROGRAMS_DESC=	Build diagnostic programs
PROGRAMS_CONFIGURE_ENABLE=programs

post-patch:
	@${REINPLACE_CMD} -e 's|^mandir=.*|mandir=${PREFIX}/share/man|' \
		${WRKSRC}/Makefile.am

.include <bsd.port.mk>
