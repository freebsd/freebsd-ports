# New ports collection makefile for:	c_c++_reference.tar.gz
# Date created:        8 March 2000
# Whom:                imura@af.airnet.ne.jp
#
# $FreeBSD$
#

PORTNAME=	c_c++_reference
PORTVERSION=	1.08
CATEGORIES=	devel
MASTER_SITES=	ftp://129.187.206.68/pub/unix/ide/KDevelop/documentation/ \
		ftp://gd.tuwien.ac.at/hci/KDevelop/documentation/ \
		ftp://fara.cs.uni-potsdam.de/pub/kdevelop/documentation/
DISTNAME=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org

RUN_DEPENDS=	kdevelop:${PORTSDIR}/devel/kdevelop

EXTRACT_ONLY=	# none
NO_BUILD=	yes

do-install:
	${TAR} -xzf ${DISTDIR}/c_c++_reference.tar.gz -C ${PREFIX}
	${CHOWN} -R 0:0 ${PREFIX}/share/doc/HTML/en/kdevelop/reference

.include <bsd.port.mk>
