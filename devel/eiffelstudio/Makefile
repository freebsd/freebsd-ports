# Created by: alepulver
# $FreeBSD$

PORTNAME=	eiffelstudio
PORTVERSION=	5.7
PORTREVISION=	7
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/EiffelStudio%20${PORTVERSION}/Build%2064493/
DISTNAME=	Eiffel${PORTVERSION:S/.//}_gpl_64493-freebsd-${EIFFEL_ARCH}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Complete Integrated Development Environment for Eiffel

LIB_DEPENDS=	libc.so.6:misc/compat6x

USES=		shebangfix
SHEBANG_FILES=	library/event/example/gen_action_sequences \
		library/vision2/interface/events/gen_action_sequences \
		library/vision2/interface/events/gen_event_sensitive
USE_GNOME=	gtk20
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

.include <bsd.port.pre.mk>

# Try native version first, then try i386 compatibility framework.
.for arch in ${ARCH}
. if ${NATIVE_ARCHS:M${arch}} != ""
EIFFEL_ARCH=		${arch:S/i386/x86/:S/amd64/x86-64/}
. else
IA32_BINARY_PORT=	yes
EIFFEL_ARCH=		x86
. endif
.endfor

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${CP} -R ${WRKSRC}/* ${STAGEDIR}${DATADIR}
	${FIND} ${STAGEDIR}${DATADIR} -type d -empty -delete
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
.for f in libgtk-x11-2.0.so.600 libgdk-x11-2.0.so.600 libatk-1.0.so.600 \
    libgdk_pixbuf-2.0.so.600 libpangoxft-1.0.so.800 libpangox-1.0.so.800 \
    libpango-1.0.so.800 libgobject-2.0.so.600 libgmodule-2.0.so.600 \
    libgthread-2.0.so.600 libglib-2.0.so.600
	${LN} -sf ${LOCALBASE}/lib/${f:C/\.[[:digit:]]+$//} \
		${STAGEDIR}${DATADIR}/studio/spec/${EIFFEL_HOST}/lib/${f}
.endfor

.include <bsd.port.post.mk>
