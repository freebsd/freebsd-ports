# New ports collection makefile for:	libelf
# Date created:		18 Apr 2001
# Whom:			roam@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	libelf
PORTVERSION=	0.8.6
CATEGORIES=	devel
MASTER_SITES=	http://www.mr511.de/software/ \
		${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	libs

MAINTAINER=	roam@FreeBSD.org
COMMENT=	A public ELF file access library similar to libelf(3) in Solaris

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -lintl"
CONFIGURE_ARGS+=	--enable-shared --disable-compat
INSTALLS_SHLIB=	yes
PLIST_SUB+=	LIBVER=${PORTVERSION:R}
USE_GETTEXT=	yes

NOMAN=		defined

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 600102

FILES_TO_PATCH=lib/32.fsize.c lib/64.xlatetof.c lib/cook.c lib/gelf.h lib/gelftrans.c

post-patch:
	${REINPLACE_CMD} \
	-e 's/Elf64_Xword/Elf64_Word/g' \
	-e 's/Elf64_Sxword/Elf64_Sword/g' \
	${FILES_TO_PATCH:S,^,${WRKSRC}/,}

.endif

.include <bsd.port.post.mk>
