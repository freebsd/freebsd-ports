# New ports collection makefile for:	pymol
# Date created:			July 18, 2002
# Whom:				Nakata Maho <chat95@mbox.kyoto-inet.or.jp>
#
# $FreeBSD$

PORTNAME=	pymol
PORTVERSION=	0.97
CATEGORIES=	biology python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	pymol
DISTNAME=	pymol-${PORTVERSION:S/./_/}-src
EXTRACT_SUFX=	.tgz

MAINTAINER=	maho@FreeBSD.org
COMMENT=	Free and Open-Source molecular modeling system

BUILD_DEPENDS=	${PYNUMERIC}
RUN_DEPENDS=	${PYNUMERIC} \
		${PYTHON_SITELIBDIR}/Pmw:${PORTSDIR}/x11-toolkits/pmw
LIB_DEPENDS=	glut.3:${PORTSDIR}/graphics/libglut \
		png.5:${PORTSDIR}/graphics/png

WRKSRC=		${WRKDIR}/pymol-${PORTVERSION}
USE_GMAKE=	yes
USE_REINPLACE=	yes
USE_PYTHON=	yes

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64" || ${ARCH} == "amd64" || ${ARCH} == "ia64"
PICFLAG?=	-fPIC
.else
PICFLAG?=	-fpic
.endif

pre-patch:
	@${INSTALL_DATA} ${WRKSRC}/setup/Rules.linux ${WRKSRC}/Rules.make
.if ${PYTHON_REL} >= 230
	@${REINPLACE_CMD} -e 's,@DEFS@,,g' ${WRKSRC}/contrib/modules/Makefile.pre.in.src
.endif

post-patch:
	@${INSTALL_DATA} ${WRKSRC}/setup/pymol.com.linux-rh7x ${WRKSRC}/setup/pymol.com
	@${REINPLACE_CMD} -e 's,@PREFIX@,${PREFIX},g' -e 's,@LOCALBASE@,${LOCALBASE},g' ${WRKSRC}/setup/pymol.com
	@${REINPLACE_CMD} -e 's,@PREFIX@,${PREFIX},g' \
		-e 's,examples\(/devel/cgo03.py\),${EXAMPLESDIR}\1,' \
		${WRKSRC}/modules/pmg_tk/Demo.py
	@${RM} -f ${WRKSRC}/modules/pmg_tk/Demo.py.*
	${REINPLACE_CMD} -e 's,@PYTHON_VERSION@,${PYTHON_VERSION},g' \
		-e 's,@LOCALBASE@,${LOCALBASE},g' \
		-e 's,@X11BASE@,${X11BASE},g' \
		-e 's,@CFLAGS@,${CFLAGS},g' \
		-e 's,@CC@,${CC},g' \
		-e 's,@PICFLAG@,${PICFLAG},g' ${WRKSRC}/Rules.make

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/setup/pymol.com ${PREFIX}/bin/pymol
	@${MKDIR} ${PREFIX}/share/pymol
	@${TAR} -C ${WRKSRC} -chf - modules test | \
		${TAR} -xf - -C ${PREFIX}/share/pymol
.if !defined(NOPORTDOCS)
	@${MKDIR} ${EXAMPLESDIR}
	@${TAR} -C ${WRKSRC}/examples --exclude package -chf - . | \
		${TAR} -xf - -C ${EXAMPLESDIR}
.endif
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${PREFIX}/share/pymol/modules
	@${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py ${PREFIX}/share/pymol/modules

.include <bsd.port.post.mk>
