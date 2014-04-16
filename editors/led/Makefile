# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	led
PORTVERSION=	2.0
CATEGORIES=	editors
MASTER_SITES=	SF/${PORTNAME}-editor/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tiny text editor, with a number of useful programming features

LICENSE=	BSD3CLAUSE

USES=		perl5
GNU_CONFIGURE=	yes
MAKE_JOBS_UNSAFE=	yes

SUB_FILES=	pkg-message

post-patch:
	@${REINPLACE_CMD} -E 's,(bin|lib|data)dir),DESTDIR)$$(&,' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
