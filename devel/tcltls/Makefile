# New ports collection makefile for:	tclgetopts
# Date created:				4 May 2000
# Whom:					mi@aldan.algebra.com
#
# $FreeBSD$
#

PORTNAME=	tcltls
PORTVERSION=	1.3
CATEGORIES=	devel tcl80 tcl82 tcl83
MASTER_SITES=	http://www.sensus.org/tcl/
DISTNAME=	tls${PORTVERSION:S/.//}

MAINTAINER=	mi@aldan.algebra.com

LIB_DEPENDS=	crypto:${PORTSDIR}/security/openssl

WRKSRC=		${WRKDIR}/tls1.3/unix

GNU_CONFIGURE=	yes

pre-patch:
	# Fixing the end-of-lines:
	for f in `find ${WRKSRC}/.. -type f` ; do \
		${TR} -d '\015' < $$f > $$f.noms && \
			${CAT} $$f.noms > $$f && ${RM} $$f.noms; done

PLIST_SUB+=	TCL_VER=${TCL_VER}

post-install:
	${MKDIR} ${PREFIX}/share/doc/tls1.3
	${MV} ${PREFIX}/lib/tls1.3/tls.htm ${PREFIX}/share/doc/tls1.3
	${MV} ${PREFIX}/lib/tls1.3/libtls${TCL_VER}.so.1 ${PREFIX}/lib
	${LN} -sf libtls${TCL_VER}.so.1 ${PREFIX}/lib/libtls${TCL_VER}.so

.include <bsd.port.pre.mk>

.if !defined(SSL_DIR)
.if exists(${PREFIX}/openssl)
SSL_DIR=	${PREFIX}/openssl
.else
SSL_DIR=	/usr
.endif
.endif

CONFIGURE_ARGS+=	--with-ssl-dir="${SSL_DIR}"

.if (!defined(WITH_TCL80) && !defined(WITH_TCL82) && !defined(WITH_TCL83))
.if exists(${PREFIX}/bin/tclsh8.3)
WITH_TCL83=	yes
.elseif exists(${PREFIX}/bin/tclsh8.2)
WITH_TCL82=	yes
.else
WITH_TCL80=	yes
.endif
.endif

.if defined(WITH_TCL80)
LIB_DEPENDS=	tcl80.1:${PORTSDIR}/lang/tcl80
CONFIGURE_ENV+=	TCLLIB=${PREFIX}/lib/tcl8.0
TCLVERMSG=	"Building for Tcl 8.0"
TCL_VER=	80
.endif

.if defined(WITH_TCL82)
LIB_DEPENDS=	tcl82.1:${PORTSDIR}/lang/tcl82
CONFIGURE_ENV+=	TCLLIB=${PREFIX}/lib/tcl8.2
TCLVERMSG=	"Building for Tcl 8.2"
TCL_VER=	82
.endif

.if defined(WITH_TCL83)
LIB_DEPENDS=	tcl83.1:${PORTSDIR}/lang/tcl83
CONFIGURE_ENV+=	TCLLIB=${PREFIX}/lib/tcl8.3
TCLVERMSG=	"Building for Tcl 8.3"
TCL_VER=	83
.endif

pre-fetch:
	#	${TCLVERMSG}
	#	"Define WITH_TCL80, or WITH_TCL82, or WITH_TCL83"
	#	"To compile against a different version of TCL"

.include <bsd.port.post.mk>
