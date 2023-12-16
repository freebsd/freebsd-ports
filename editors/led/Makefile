PORTNAME=	led
PORTVERSION=	2.0
PORTREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	SF/${PORTNAME}-editor/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tiny text editor, with a number of useful programming features
WWW=		https://led-editor.sourceforge.net/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Last upstream release was in 2002 reconsider using editors/nano
EXPIRATION_DATE=	2024-01-16

USES=		ncurses perl5
GNU_CONFIGURE=	yes
MAKE_JOBS_UNSAFE=	yes

SUB_FILES=	pkg-message

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400091 || ( ${OSVERSION} >= 1302507 && ${OSVERSION} < 1400000 ))
CFLAGS+=	-Wno-error=incompatible-function-pointer-types
.endif

post-patch:
	@${REINPLACE_CMD} -E 's,(bin|lib|data)dir),DESTDIR)$$(&,' \
		${WRKSRC}/Makefile.in

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/led \
		${STAGEDIR}${PREFIX}/lib/led/modules/perlapi.so

.include <bsd.port.mk>
