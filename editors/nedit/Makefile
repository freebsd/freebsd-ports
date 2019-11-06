# Created by: Daniel Eischen <deischen@FreeBSD.org>
# $FreeBSD$

PORTNAME=	nedit
PORTVERSION=	5.7
CATEGORIES=	editors
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-source
DISTFILES=	nedit-${PORTVERSION}-src.tar.gz \
		nedit.app-defaults
EXTRACT_ONLY=	nedit-${PORTVERSION}-src.tar.gz

MAINTAINER=	swills@FreeBSD.org
COMMENT=	X11/Motif GUI text editor for programs and plain text files

BROKEN=		unfetchable

LICENSE=	GPLv1

USES=		motif perl5 xorg
USE_PERL5=	build
ALL_TARGET=	freebsd

PLIST_FILES=	bin/nclient \
		bin/nedit \
		lib/X11/app-defaults/NEdit.ad \
		man/man1/nclient.1.gz \
		man/man1/nedit.1.gz

post-extract:
	${CP} ${DISTDIR}/nedit.app-defaults ${WRKSRC}/NEdit.ad

post-build:
	cd ${WRKSRC} && make docs

post-install::
.for file in nedit nclient
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${file}
.endfor

.include <bsd.port.mk>
