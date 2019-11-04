# Created by: alepulver
# $FreeBSD$

PORTNAME=	eiffelstudio
PORTVERSION=	5.7
PORTREVISION=	8
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/EiffelStudio%20${PORTVERSION}/Build%2064493/
DISTNAME=	Eiffel${PORTVERSION:S/.//}_gpl_64493-freebsd-${EIFFEL_ARCH}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Complete Integrated Development Environment for Eiffel

USES=		shebangfix
SHEBANG_FILES=	library/event/example/gen_action_sequences \
		library/vision2/interface/events/gen_action_sequences \
		library/vision2/interface/events/gen_event_sensitive
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/Eiffel${PORTVERSION:S/.//}

SUB_FILES=	${PORTNAME} pkg-message
DATADIR=	${PREFIX}/lib/${PORTNAME}

NATIVE_ARCHS=	i386 amd64
EIFFEL_HOST=	${OPSYS:tl}-${EIFFEL_ARCH}
PLIST_SUB+=	EIFFEL_HOST="${EIFFEL_HOST}"
SUB_LIST+=	EIFFEL_HOST="${EIFFEL_HOST}"

PLIST_FILES=	bin/${PORTNAME}
PORTDATA=	*

.include <bsd.port.options.mk>

# Try native version first, then try i386 compatibility framework.
.for arch in ${ARCH}
. if ${NATIVE_ARCHS:M${arch}} != ""
EIFFEL_ARCH=		${arch:S/i386/x86/:S/amd64/x86-64/}
. else
IA32_BINARY_PORT=	yes
EIFFEL_ARCH=		x86
. endif
.endfor

.if ${EIFFEL_ARCH} == x86
LIB_DEPENDS=	libc.so.5:misc/compat5x
USES+=		gnome xorg
USE_GNOME=	gtk20 pangox-compat
USE_XORG=	x11 xcursor xext xft xi xinerama xrandr xrender xtst
.elif ${EIFFEL_ARCH} == x86_64
USES+=		gnome xorg
LIB_DEPENDS=	libc.so.6:misc/compat6x
USE_GNOME=	gtk20
USE_XORG=	x11 xtst
.endif

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${CP} -R ${WRKSRC}/* ${STAGEDIR}${DATADIR}
	${FIND} ${STAGEDIR}${DATADIR} -type d -empty -delete
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
.if ${EIFFEL_ARCH} == x86
.for f in libgtk-x11-2.0.so.400 libgdk-x11-2.0.so.400 libatk-1.0.so.600 \
    libgdk_pixbuf-2.0.so.400 libpangoxft-1.0.so.399 libpangox-1.0.so.399 \
    libpango-1.0.so.399 libgobject-2.0.so.400 libgmodule-2.0.so.400 \
    libgthread-2.0.so.400 libglib-2.0.so.400 libfreetype.so.9 libiconv.so.3
	${LN} -sf ${LOCALBASE}/lib/${f:C/\.[[:digit:]]+$//} \
		${STAGEDIR}${DATADIR}/studio/spec/${EIFFEL_HOST}/lib/${f}
.endfor
.elif ${EIFFEL_ARCH} == x86_64
.for f in libgtk-x11-2.0.so.600 libgdk-x11-2.0.so.600 libgdk_pixbuf-2.0.so.600 \
    libpango-1.0.so.800 libgobject-2.0.so.600 libgmodule-2.0.so.600 \
    libgthread-2.0.so.600 libglib-2.0.so.600
	${LN} -sf ${LOCALBASE}/lib/${f:C/\.[[:digit:]]+$//} \
		${STAGEDIR}${DATADIR}/studio/spec/${EIFFEL_HOST}/lib/${f}
.endfor
.endif

.include <bsd.port.mk>
