PORTNAME=	gtimer
PORTVERSION=	2.0.0
PORTREVISION=	6
CATEGORIES=	deskutils
MASTER_SITES=	SF/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Timer for your personal activities
WWW=		https://www.k5n.us/gtimer.php

LICENSE=	GPLv2

RUN_DEPENDS=	xdg-open:devel/xdg-utils

USES=		gettext gmake gnome localbase perl5 pkgconfig xorg
USE_GNOME=	gtk20
USE_XORG=	x11 xscrnsaver

GNU_CONFIGURE=	yes

CPPFLAGS+=	-Wno-return-type
LIBS+=		-lX11

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400091 || ( ${OSVERSION} >= 1302507 && ${OSVERSION} < 1400000 ))
CFLAGS+=	-Wno-error=incompatible-function-pointer-types
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|1.1.7|${PORTVERSION}|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|"sensible-browser"|"xdg-open"|g' ${WRKSRC}/config.h
.for file in project.c task.c
	@${REINPLACE_CMD} -e 's|<malloc\.h>|<stdlib.h>|g' ${WRKSRC}/${file}
.endfor

pre-build:
	@(cd ${WRKSRC} && ${PERL} ./txt2h.pl < ChangeLog > changelog.h)

post-build:
.for lang in cs cz es fr sv
	cd ${WRKSRC}/po && ${LOCALBASE}/bin/msgfmt -o ${lang}.mo ${lang}.po
.endfor

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${PREFIX}/share/man/man1
.for lang in cs cz es fr sv
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/locale/${lang}/LC_MESSAGES
	${INSTALL_DATA} ${WRKSRC}/po/${lang}.mo \
		${STAGEDIR}${PREFIX}/share/locale/${lang}/LC_MESSAGES/${PORTNAME}.mo
.endfor

.include <bsd.port.mk>
