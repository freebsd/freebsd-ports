# New ports collection makefile for:	gperiodic
# Date created:				16 July 1999
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	gperiodic
PORTVERSION=	2.0.7
PORTREVISION=	1
CATEGORIES=	biology
MASTER_SITES=	http://www.acclab.helsinki.fi/~frantz/software/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Displays a periodic table of the elements

USE_X_PREFIX=	yes
USE_GNOME=	gtk20
MAKE_ARGS=	CC="${CC} ${CFLAGS}"
ALL_TARGET=	${PORTNAME}

LANGS=	da fr pl sv tr

post-build:
.for lang in ${LANGS}
	cd ${WRKSRC}/po && msgfmt -f -v -o ${lang}.mo ${lang}.po
.endfor

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gperiodic ${PREFIX}/bin
.for lang in ${LANGS}
	@${MKDIR} ${PREFIX}/share/locale/${lang}/LC_MESSAGES
	${INSTALL_DATA} ${WRKSRC}/po/${lang}.mo \
		${PREFIX}/share/locale/${lang}/LC_MESSAGES/${PORTNAME}.mo
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in AUTHORS ChangeLog README
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
