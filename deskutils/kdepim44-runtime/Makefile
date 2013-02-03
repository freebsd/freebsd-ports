# Created by: miwi
# $FreeBSD$

PORTNAME=	kdepim-runtime
PORTVERSION=	4.4.11.1
PORTREVISION=	2
CATEGORIES=	deskutils kde ipv6
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/kdepim-${PORTVERSION}/src
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Libraries for KDE-PIM applications

LIB_DEPENDS=	boost_thread:${PORTSDIR}/devel/boost-libs

CONFLICTS_INSTALL=	kdepim-runtime-4.[89].*
LATEST_LINK=	${PORTNAME}44

USE_KDE4=	pimlibs kdeprefix kdehier sharedmime automoc4
KDE4_BUILDENV=	yes
USE_BZIP2=	yes
USE_QT4=	qmake_build moc_build rcc_build uic_build
MAKE_JOBS_SAFE=	yes

post-patch:
	${GREP} -H -r "#include <q" ${WRKSRC} | ${CUT} -d: -f1 | uniq | \
		${XARGS} ${REINPLACE_CMD} -f ${FILESDIR}/qt3to4headers.txt

.include <bsd.port.mk>
