# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	led
PORTVERSION=	2.0
PORTREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	SF/${PORTNAME}-editor/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tiny text editor, with a number of useful programming features

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		ncurses perl5
GNU_CONFIGURE=	yes
MAKE_JOBS_UNSAFE=	yes

SUB_FILES=	pkg-message

post-patch:
	@${REINPLACE_CMD} -E 's,(bin|lib|data)dir),DESTDIR)$$(&,' \
		${WRKSRC}/Makefile.in

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/led \
		${STAGEDIR}${PREFIX}/lib/led/modules/perlapi.so

.include <bsd.port.mk>
