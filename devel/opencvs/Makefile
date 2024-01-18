PORTNAME=	opencvs
PORTVERSION=	20151230
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.stack.nl/pub/users/johans/opencvs/ \
		LOCAL/johans

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	BSD-licensed CVS implementation
WWW=		http://www.opencvs.org/

LICENSE=	BSD2CLAUSE

WRKSRC=		${WRKDIR}/cvs

USES=		uidfix
MAKE_ENV+=	BINDIR="${PREFIX}/bin" \
		MANDIR="${PREFIX}/share/man/man" \
		CATDIR="${PREFIX}/share/man/man"

PLIST_FILES=	bin/opencvs \
		share/man/man1/opencvs.1.gz \
		share/man/man5/opencvs.5.gz \
		share/man/man7/cvsintro.7.gz

.include <bsd.port.mk>
