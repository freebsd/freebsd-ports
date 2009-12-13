# New ports collection makefile for:	coverhunter
# Date created:			14 Jul 2004
# Whom:				Jean-Yves Lefort <jylefort@brutele.be>
#
# $FreeBSD$
#

PORTNAME=		coverhunter
PORTVERSION=		0.3
PORTREVISION=	5
CATEGORIES=		audio graphics
MASTER_SITES=		SF

MAINTAINER=		ports@FreeBSD.org
COMMENT=		A program fetching the covers of your digital music albums

RUN_DEPENDS=		${PYTHON_SITELIBDIR}/PIL/__init__.py:${PORTSDIR}/graphics/py-imaging

USE_XORG=	x11
USE_GNOME=		pygtk2
USE_PYTHON=		2.4+
NO_BUILD=		yes

PYC=			PYTHON="${PYTHON_CMD}" ${SH} ${SCRIPTDIR}/py-compile

BINDIR=			${PREFIX}/bin
PKGLIBDIR=		${PREFIX}/lib/coverhunter

MODULES=		__init__.py \
			album.py \
			amazon.py \
			config.py \
			libhunter.py \
			musicfile.py \
			source.py

post-patch:
	@${REINPLACE_CMD} -e \
		's|@PYTHON_CMD@|${PYTHON_CMD}|; \
		 s|@PKGLIBDIR@|${PKGLIBDIR}|; \
		 s|@DATADIR@|${DATADIR}|' ${WRKSRC}/bin/coverhunter

do-install:
	${MKDIR} ${BINDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/bin/coverhunter ${BINDIR}
	${MKDIR} ${PKGLIBDIR}
.for module in ${MODULES}
	${INSTALL_DATA} ${WRKSRC}/lib/${module} ${PKGLIBDIR}
	${PYC} --basedir ${PKGLIBDIR} ${PKGLIBDIR}/${module}
.endfor
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} \
		${WRKSRC}/data/CoverHunter.glade \
		${WRKSRC}/data/fetch_all.png \
		${WRKSRC}/data/nocover.gif \
		${WRKSRC}/data/picture.png \
		${WRKSRC}/data/searching.png \
		${DATADIR}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
