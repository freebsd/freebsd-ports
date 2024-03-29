PORTNAME=	libphk
PORTVERSION=	0.3.20080902
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	http://phk.freebsd.dk/phkrel/
DISTNAME=	Libphk.${PORTVERSION:C/0.3.//}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	PHK's utilities functions
WWW=		http://phk.freebsd.dk/phkrel/

LICENSE=	Beerware
LICENSE_NAME=	Beerware
LICENSE_TEXT=	"THE BEER-WARE LICENSE" (Revision 42): \
		<phk@FreeBSD.ORG> wrote this file.  As long as you retain this notice you \
		can do whatever you want with this stuff. If we meet some day, and you think \
		this stuff is worth it, you can buy me a beer in return.   Poul-Henning Kamp
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		uidfix tar:tgz

MAKE_FLAGS+=	MANDIR=${PREFIX}/share/man/man

# XXX static PIE libraries not yet supported by the base system
MAKE_FLAGS+=	WITHOUT_PIE=true
MAKE_JOBS_UNSAFE=	yes

WRKSRC=		${WRKDIR}/Libphk

.include <bsd.port.options.mk>

.if defined(NO_PROFILE) || ( ${OPSYS} == FreeBSD && ${OSVERSION} >= 1400079 )
CFLAGS+=	-Wno-error=unused-but-set-variable
PLIST_SUB+=	PROFILE="@comment "
.else
PLIST_SUB+=	PROFILE=""
.endif

post-patch:
	@${SED} -i -e 's!/usr/local!$${PREFIX}!g' ${WRKSRC}/Makefile

.include <bsd.port.mk>
