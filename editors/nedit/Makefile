# Created by: Daniel Eischen <deischen@FreeBSD.org>
# $FreeBSD$

PORTNAME=	nedit
PORTVERSION=	5.6
PORTREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	http://people.freebsd.org/~deischen/distfiles/ \
		${MASTER_SITE_SOURCEFORGE} \
		ftp://ftp.nluug.nl/pub/editors/NEdit/contrib/misc/
MASTER_SITE_SUBDIR=	${PORTNAME}/${PORTNAME}-source
DISTFILES=	nedit-5.6a-src.tar.gz nedit.app-defaults
EXTRACT_ONLY=	nedit-5.6a-src.tar.gz

MAINTAINER=	deischen@FreeBSD.org
COMMENT=	X11/Motif GUI text editor for programs and plain text files

LICENSE=	GPLv1

USES=		motif
USE_XORG=	xpm
ALL_TARGET=	freebsd

PLIST_FILES=	bin/nclient \
		bin/nedit \
		man/man1/nclient.1.gz \
		man/man1/nedit.1.gz \
		lib/X11/app-defaults/NEdit.ad

post-extract:
	${CP} ${DISTDIR}/nedit.app-defaults ${WRKSRC}/NEdit.ad

post-build:
	cd ${WRKSRC} && make docs

post-install::
.for file in nedit nclient
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${file}
.endfor

.include <bsd.port.mk>
