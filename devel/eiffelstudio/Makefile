# New ports collection makefile for:	eiffelstudio
# Date created:				2007-01-01
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	eiffelstudio
PORTVERSION=	5.7
PORTREVISION=	3
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

MAINTAINER=	alepulver@FreeBSD.org
COMMENT=	A Complete Integrated Development Environment for Eiffel

LIB_DEPENDS=	c.5:${PORTSDIR}/misc/compat5x

USE_GNOME=	gtk20
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/Eiffel${PORTVERSION:S/.//}

SUB_FILES=	${PORTNAME} pkg-message
DATADIR=	${PREFIX}/lib/${PORTNAME}

NATIVE_ARCHS=	i386 amd64
EIFFEL_HOST=	${OPSYS:L}-${EIFFEL_ARCH}
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
PLIST_SUB+=	${arch:U}=""
. else
PLIST_SUB+=	${arch:U}="@comment "
. endif
.endfor

do-install:
	${MKDIR} ${DATADIR}
	${CP} -R ${WRKSRC}/* ${DATADIR}
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${PREFIX}/bin
.for f in libgtk-x11-2.0.so.400 libgdk-x11-2.0.so.400 libatk-1.0.so.600 \
    libgdk_pixbuf-2.0.so.400 libpangoxft-1.0.so.399 libpangox-1.0.so.399 \
    libpango-1.0.so.399 libgobject-2.0.so.400 libgmodule-2.0.so.400 \
    libgthread-2.0.so.400 libglib-2.0.so.400
	${LN} -sf ${LOCALBASE}/lib/${f:C/\.[[:digit:]]+$//} \
		${DATADIR}/studio/spec/${EIFFEL_HOST}/lib/${f}
.endfor

post-install:
	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}

.include <bsd.port.post.mk>
