# New ports collection Makefile for:	komodo-edit
# Date created:				2008-02-13
# Whom:					arved
#
# $FreeBSD$

PORTNAME=	komodo-edit
PORTVERSION=	5.2.4
CATEGORIES=	editors
MASTER_SITES=	http://downloads.activestate.com/Komodo/releases/${PORTVERSION}/
DISTNAME=	Komodo-Edit-${PORTVERSION}-4343-linux-libcpp6-x86

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Multi-language editor from ActiveState

ONLY_FOR_ARCHS=	i386 amd64
NO_BUILD=	yes
USE_LINUX=	f10
USE_LINUX_APPS=	gtk2 jpeg
USE_LDCONFIG=	yes
USE_PYTHON=	yes

.include <bsd.port.pre.mk>

do-install:
	${MKDIR} ${DATADIR}
	(cd ${WRKSRC}/INSTALLDIR && ${COPYTREE_SHARE} . ${DATADIR})
	(cd ${WRKSRC}/INSTALLDIR && ${COPYTREE_BIN} . ${DATADIR} "-type f -a -perm 755")
	${LN} -sf ${DATADIR}/bin/komodo ${PREFIX}/bin/komodo

.include <bsd.port.post.mk>
