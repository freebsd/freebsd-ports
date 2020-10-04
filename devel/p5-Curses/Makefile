# Created by: James FitzGibbon <jfitz@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Curses
PORTVERSION=	1.37
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl5 module for terminal screen handling and optimization

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE_ART10=	${WRKSRC}/Artistic
LICENSE_FILE_GPLv1+ =	${WRKSRC}/Copying

USES=		perl5
USE_PERL5=	configure

CONFIGURE_ARGS=	PANELS MENUS FORMS
CONFIGURE_ENV=	CURSES_CFLAGS="-I${WRKSRC}/usr/include/ncurses"

OPTIONS_DEFINE=	NCURSESW
NCURSESW_DESC=	Wide-character-capable support by ncursesw library
NCURSESW_CONFIGURE_ENV=		CURSES_LDFLAGS="-L/usr/lib/ -lncursesw" \
				CURSES_LIBTYPE="ncursesw"
NCURSESW_CONFIGURE_ENV_OFF=	CURSES_LDFLAGS="-L/usr/lib/ -lncurses"

pre-configure:
	@${LN} -fs ${WRKSRC}/hints/c-freebsd.ncurses.h ${WRKSRC}/c-config.h
	@${MKDIR} ${WRKSRC}/usr/include/ncurses
.for i in form.h ncurses.h menu.h panel.h
	@${LN} -fs /usr/include/${i} ${WRKSRC}/usr/include/ncurses/${i}
.endfor

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Curses/Curses.so

.include <bsd.port.mk>
