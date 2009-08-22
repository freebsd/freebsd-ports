# ex:ts=8
# Ports collection makefile for:	e4graph
# Date created:			Jul 16, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	e4graph
PORTVERSION=	1.0a11
PORTREVISION=	3
CATEGORIES=	devel tcl
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-source/${PORTNAME}-${PORTVERSION}
EXTRACT_SUFX=	.src.tar.gz

MAINTAINER=	dan@rucci.org
COMMENT=	A C++ library that persistently stores graph like data

LIB_DEPENDS=	mk4.0:${PORTSDIR}/databases/metakit \
		tcl${TCLVND}:${PORTSDIR}/lang/tcl${TCLVND} \
		expat.6:${PORTSDIR}/textproc/expat2

WRKSRC=		${WRKDIR}/${DISTNAME}/all

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-metakit=${LOCALBASE} \
		--with-tcl=${LOCALBASE}/lib/tcl${TCL_VER} --enable-tcl \
		--with-expat=${LOCALBASE} --enable-xml
CFLAGS+=	-fpermissive -I${LOCALBASE}/include/tcl${TCL_VER}
MAKEFILE=	makefile
USE_LDCONFIG=	yes
PLIST_SUB=	TCL_VER="${TCL_VER}"

.if defined(WITH_PYTHON)
USE_PYTHON=	yes
CONFIGURE_ARGS+=	--enable-python
PLIST_SUB+=	PYTHON=""
.else
PLIST_SUB+=	PYTHON="@comment "
.endif

TCL_VER?=	8.4
TCLVND=		${TCL_VER:S/.//}

post-patch:
	@${REINPLACE_CMD} -e 's|=-O$$|="$${CFLAGS}"|g ; \
		s|gcc -shared|$$(CC) -shared|g ; \
		s|$${CONFIG_SHELL-/bin/sh} $$ac_aux_dir|$$ac_aux_dir|' \
			${WRKSRC}/configure
	@${CHMOD} +x ${WRKSRC}/scripts/ltconfig

post-install:
.for file in testcore testcores
	@${STRIP_CMD} ${PREFIX}/bin/${file}
.endfor

.include <bsd.port.mk>
