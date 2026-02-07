PORTNAME=	mp3wrap
PORTVERSION=	0.5
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}%20${PORTVERSION}
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Merge mp3 files (and other formats)
WWW=		https://mp3wrap.sourceforge.net/

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

PLIST_FILES=	bin/mp3wrap share/man/man1/mp3wrap.1.gz

.include <bsd.port.mk>
