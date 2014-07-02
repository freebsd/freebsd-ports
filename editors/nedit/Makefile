# Created by: Daniel Eischen <deischen@FreeBSD.org>
# $FreeBSD$

PORTNAME=	nedit
PORTVERSION=	5.5
PORTREVISION=	4
CATEGORIES=	editors
MASTER_SITES=	http://people.freebsd.org/~deischen/distfiles/ \
		${MASTER_SITE_SOURCEFORGE} \
		ftp://ftp.nluug.nl/pub/editors/NEdit/contrib/misc/
MASTER_SITE_SUBDIR=	${PORTNAME}/${PORTNAME}-source/${PORTVERSION}
DISTFILES=	nedit-5.5-src.tar.bz2 nedit.app-defaults
EXTRACT_ONLY=	nedit-5.5-src.tar.bz2

MAINTAINER=	deischen@FreeBSD.org
COMMENT=	X11/Motif GUI text editor for programs and plain text files

LICENSE=	GPLv1

USES=		motif tar:bzip2
USE_XORG=	xpm
ALL_TARGET=	freebsd

post-extract:
	${CP} ${DISTDIR}/nedit.app-defaults ${WRKSRC}/NEdit.ad

post-install::
.for file in nedit nclient
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${file}
.endfor

.include <bsd.port.mk>
