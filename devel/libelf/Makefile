# New ports collection makefile for:	libelf
# Date created:		18 Apr 2001
# Whom:			roam@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	libelf
PORTVERSION=	0.8.12
CATEGORIES=	devel
MASTER_SITES=	http://www.mr511.de/software/ \
		${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	libs

MAINTAINER=	roam@FreeBSD.org
COMMENT=	A public ELF file access library similar to libelf(3) in Solaris

OPTIONS=	EXTENDED	"ELF format extensions" on \
		NLS		"Native Language Support" on \
		SANITY		"Avoid loading invalid ELF files" on

.include <bsd.port.pre.mk>

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--enable-shared --disable-compat
USE_LDCONFIG=	yes

NOMAN=		defined

.if !defined(WITHOUT_NLS)
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -lintl"
CONFIGURE_ARGS+=	--enable-nls
USE_GETTEXT=	yes
PLIST_SUB+=	GETTEXT=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	GETTEXT="@comment "
.endif

.if !defined(WITHOUT_EXTENDED)
CONFIGURE_ARGS+=	--enable-extended-format
.else
CONFIGURE_ARGS+=	--disable-extended-format
.endif

.if !defined(WITHOUT_SANITY)
CONFIGURE_ARGS+=	--enable-sanity-checks
.else
CONFIGURE_ARGS+=	--disable-sanity-checks
.endif

.if ${OSVERSION} < 600102

FILES_TO_PATCH=lib/32.fsize.c lib/64.xlatetof.c lib/cook.c lib/gelf.h lib/gelftrans.c

post-patch:
	${REINPLACE_CMD} \
	-e 's/Elf64_Xword/Elf64_Word/g' \
	-e 's/Elf64_Sxword/Elf64_Sword/g' \
	${FILES_TO_PATCH:S,^,${WRKSRC}/,}

.endif

.include <bsd.port.post.mk>
