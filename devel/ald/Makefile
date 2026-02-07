PORTNAME=		ald
PORTVERSION=		0.1.7
PORTREVISION=		3
CATEGORIES=		devel
MASTER_SITES=		SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=		alken@colorado.edu
COMMENT=		Debugger for assembly level programs
WWW=			https://ald.sourceforge.net

ONLY_FOR_ARCHS=		i386
USES=			readline

GNU_CONFIGURE=		yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share

PLIST_FILES=		bin/ald share/man/man8/ald.8.gz
NOPRECIOUSMAKEVARS=	yes

.include <bsd.port.mk>
