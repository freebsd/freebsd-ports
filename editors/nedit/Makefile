PORTNAME=	nedit
DISTVERSION=	5.8
CATEGORIES=	editors
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-source/
DISTFILES=	nedit-${DISTVERSION}-src.tar.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	X11/Motif GUI text editor for programs and plain text files
WWW=		https://sourceforge.net/projects/nedit/

LICENSE=	GPLv1

USES=		motif perl5 xorg
USE_PERL5=	build
ALL_TARGET=	freebsd

PLIST_FILES=	bin/nclient \
		bin/nedit \
		lib/X11/app-defaults/NEdit.ad \
		share/man/man1/nclient.1.gz \
		share/man/man1/nedit.1.gz

post-build:
	cd ${WRKSRC} && make docs

post-install::
.for file in nedit nclient
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${file}
.endfor

.include <bsd.port.mk>
