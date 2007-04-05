# New ports collection makefile for: tclcl
# Date created:		23 April 1999
# Whom:			obonilla@fisicc-ufm.edu
#
# $FreeBSD$
#

PORTNAME=	tclcl
PORTVERSION=	1.18
DISTVERSIONPREFIX=	src-
CATEGORIES=	devel tcl84 tk84
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	otcl-tclcl

MAINTAINER=	mm@FreeBSD.org
COMMENT=	Tcl/C++ interface used by ns and nam

LIB_DEPENDS=	otcl:${PORTSDIR}/lang/otcl

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_TK=		yes
USE_TK_BUILD=	yes
USE_AUTOTOOLS=	autoconf:259
GNU_CONFIGURE=	yes

.if !defined(NOPORTDOCS)
PORTDOCS=	CHANGES.html
.endif

.include <bsd.port.pre.mk>

CONFIGURE_ARGS=	--with-tcl-ver=${TCL_VER} --with-tk-ver=${TK_VER} \
		--x-libraries=${X11BASE}/lib --x-includes=${X11BASE}/include

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tcl2c++ ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/otcldoc ${PREFIX}/bin
	${MKDIR} ${PREFIX}/include/tclcl
	${INSTALL_DATA} ${WRKSRC}/*.h ${PREFIX}/include/tclcl
	${INSTALL_DATA} ${WRKSRC}/libtclcl.a ${PREFIX}/lib
	@${LN} -sf ${PREFIX}/lib/libtclcl.a ${PREFIX}/lib/libTcl.a

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for FILE in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
