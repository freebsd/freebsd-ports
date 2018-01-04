# Created by: Ashish SHUKLA <ashish@FreeBSD.org>
# $FreeBSD$

PORTNAME=	chez-scheme
PORTVERSION=	9.5
DISTVERSIONPREFIX=	v
CATEGORIES=	lang
MASTER_SITES=	http://distfiles.pirateparty.in/ashish/:boot \
		LOCAL/ashish:boot
DISTFILES=	${PORTNAME}-boot-a6fb.tar.xz:boot \
		${PORTNAME}-boot-i3fb.tar.xz:boot

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	Chez Scheme system

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64 i386

USE_GITHUB=	yes
GH_ACCOUNT=	cisco
GH_PROJECT=	ChezScheme
GH_TUPLE=	nanopass:nanopass-framework-scheme:v1.9:nanopass/nanopass \
		madler:zlib:v1.2.11:zlib/zlib \
		dybvig:stex:v1.2.1:stex/stex

USES=		gmake iconv:lib ncurses
USE_XORG=	x11
HAS_CONFIGURE=	yes
ALL_TARGET=	build
CONFLICTS_INSTALL=	petite-chez-[0-9]*
STRIP_FILES=	bin/petite bin/${PORTNAME} bin/${PORTNAME}-script
CHEZ_LIBDIR=lib/csv${PORTVERSION}
CONFIGURE_ARGS=	--installprefix=${PREFIX} \
		--temproot=${STAGEDIR} \
		--installschemename=${PORTNAME} \
		--installscriptname=${PORTNAME}-script
PLIST_SUB=	PORTNAME=${PORTNAME} \
		CHEZ_ARCH=${CHEZ_ARCH} \
		CHEZ_LIBDIR=${CHEZ_LIBDIR}

.include <bsd.port.pre.mk>

.if (${ARCH} == "amd64")
CONFIGURE_ARGS+=	--threads --64 -m=a6fb
CHEZ_ARCH=	a6fb
.elif (${ARCH} == "i386")
CONFIGURE_ARGS+=	--threads --32 -m=i3fb
CHEZ_ARCH=	i3fb
.endif

post-patch:
	${LN} -sf ${WRKDIR}/${CHEZ_ARCH} ${WRKSRC}/boot/
	${REINPLACE_CMD} -e 's,/usr/X11R6,${LOCALBASE},g' \
		-e 's,/usr/local,${LOCALBASE},g' \
		-e 's,-liconv,${ICONV_LIB},g' ${WRKSRC}/c/Mf-${CHEZ_ARCH}

post-install:
.for f in ${STRIP_FILES}
	@${CHMOD} +w ${STAGEDIR}${PREFIX}/${f}
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/${f}
	@${CHMOD} -w ${STAGEDIR}${PREFIX}/${f}
.endfor
	@${LN} -sf scheme.boot ${STAGEDIR}${PREFIX}/${CHEZ_LIBDIR}/${CHEZ_ARCH}/${PORTNAME}-script.boot

.include <bsd.port.post.mk>
