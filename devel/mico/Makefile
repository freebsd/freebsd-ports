# Created by: Marc G. Fournier <scrappy@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mico
PORTVERSION=	2.3.13
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}%20${PORTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Secure, reliable, production-quality, standards-based CORBA middleware

LICENSE=	GPLv2 LGPL20
LICENSE_COMB=	multi
LICENSE_FILE_GPLv2=	${WRKSRC}/LICENSE-GPL
LICENSE_FILE_LGPL20=	${WRKSRC}/LICENSE-LGPL

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-optimize --with-ssl=${OPENSSLBASE}
MAKE_ARGS=	INSTDIR=${STAGEDIR}${PREFIX} SHARED_INSTDIR=${STAGEDIR}${PREFIX}
USES=		gmake ncurses readline ssl
USE_LDCONFIG=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

OPTIONS_DEFINE=	DEBUG DOCS EXAMPLES GTK1 TCL X11
OPTIONS_SUB=	yes

DEBUG_CONFIGURE_ENABLE=	debug

GTK1_CONFIGURE_ON=	--with-gtk=${LOCALBASE}	# Don't use CONFIGURE_WITH
GTK1_USE=		GNOME=gtk12

TCL_CONFIGURE_ON=	--with-tcl=${LOCALBASE}	# Don't use CONFIGURE_WITH
TCL_CPPFLAGS=		-I${TCL_INCLUDEDIR}
TCL_LIBS=		-L${LOCALBASE}/lib
TCL_USES=		tcl

X11_CONFIGURE_WITH=	x
X11_USE=		XORG=x11

post-patch:
	@${FIND} ${WRKSRC}/demo -name 'Make*' | ${XARGS} \
		${REINPLACE_CMD} 's,doc/mico/examples,${EXAMPLESDIR_REL},'
	@${REINPLACE_CMD} 's/ministl//' ${WRKSRC}/include/Makefile
	@${REINPLACE_CMD} 's/^main()/int &/' ${WRKSRC}/configure

post-install:
.for f in eventd idl imr iordump ird mico-cpp micod mkdepend nsadmin nsd propertyd timed
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${f}
.endfor
	${CHMOD} u+w ${STAGEDIR}${PREFIX}/lib/*.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/*.so
	${CHMOD} u-w ${STAGEDIR}${PREFIX}/lib/*.so

.include <bsd.port.mk>
