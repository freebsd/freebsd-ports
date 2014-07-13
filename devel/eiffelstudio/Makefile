# Created by: alepulver
# $FreeBSD$

PORTNAME=	eiffelstudio
PORTVERSION=	5.7
PORTREVISION=	6
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.cs.rit.edu/pub/mirrors/ise/download/57/ \
		ftp://ftp.inf.ethz.ch/pub/mirror/eiffel/57/ \
		ftp://ftp.deakin.edu.au/pub/eiffel/download/57/ \
		ftp://ftp.gmu.edu/eiffel/ftp.eiffel.com/pub/download/57/ \
		ftp://ftp.pucpr.br/eiffel/57/ \
		ftp://gd.tuwien.ac.at/languages/eiffel/download/57/ \
		http://gd.tuwien.ac.at/languages/eiffel/download/57/ \
		ftp://ftp.informatik.uni-stuttgart.de/pub/eiffel/mirrors/ise/download/57/ \
		ftp://ftp.eiffel.com/pub/download/57/ \
		http://ftp.eiffel.com/pub/download/57/
DISTNAME=	Eiffel${PORTVERSION:S/.//}_gpl_64493-freebsd-${EIFFEL_ARCH}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Complete Integrated Development Environment for Eiffel

LIB_DEPENDS=	libc.so.6:${PORTSDIR}/misc/compat6x

USE_GNOME=	gtk20
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/Eiffel${PORTVERSION:S/.//}

SUB_FILES=	${PORTNAME} pkg-message
DATADIR=	${PREFIX}/lib/${PORTNAME}

NATIVE_ARCHS=	i386 amd64
EIFFEL_HOST=	${OPSYS:tl}-${EIFFEL_ARCH}
PLIST_SUB+=	EIFFEL_HOST="${EIFFEL_HOST}"
SUB_LIST+=	EIFFEL_HOST="${EIFFEL_HOST}"

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

.for arch in ${NATIVE_ARCHS}
. if ${EIFFEL_ARCH} == ${arch:S/i386/x86/:S/amd64/x86-64/}
PLIST_SUB+=	${arch:tu}=""
. else
PLIST_SUB+=	${arch:tu}="@comment "
. endif
.endfor

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${CP} -R ${WRKSRC}/* ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
.for f in libgtk-x11-2.0.so.600 libgdk-x11-2.0.so.600 libatk-1.0.so.600 \
    libgdk_pixbuf-2.0.so.600 libpangoxft-1.0.so.800 libpangox-1.0.so.800 \
    libpango-1.0.so.800 libgobject-2.0.so.600 libgmodule-2.0.so.600 \
    libgthread-2.0.so.600 libglib-2.0.so.600
	${LN} -sf ${LOCALBASE}/lib/${f:C/\.[[:digit:]]+$//} \
		${STAGEDIR}${DATADIR}/studio/spec/${EIFFEL_HOST}/lib/${f}
.endfor

.include <bsd.port.post.mk>
