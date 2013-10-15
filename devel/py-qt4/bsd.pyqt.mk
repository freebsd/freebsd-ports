# bsd.pyqt.mk - Global definitions for PyQt related ports
#
# $FreeBSD$
#

PYQT_MAINTAINER=	kde@FreeBSD.org

MASTER_SITE_RIVERBANK=	http://www.riverbankcomputing.com/static/Downloads/%SUBDIR%/

MASTER_SITES_SIP=	SF/pyqt/sip/sip-${PORTVERSION} \
			${MASTER_SITE_GENTOO:S,%SUBDIR%,distfiles,}
MASTER_SITES_PYQT4=	SF/pyqt/PyQt4/PyQt-${PORTVERSION} \
			${MASTER_SITE_GENTOO:S,%SUBDIR%,distfiles,}
MASTER_SITES_QSCI2=	SF/pyqt/QScintilla2/QScintilla-${PORTVERSION} \
			${MASTER_SITE_GENTOO:S,%SUBDIR%,distfiles,}

SIP_VERSION=		4.15.2
PYQT4_VERSION=		4.10.3
QSCI2_VERSION=		2.7.2

SIP_DISTNAME=		sip-${SIP_VERSION}
PYQT4_DISTNAME=		PyQt-x11-gpl-${PYQT4_VERSION}
PYQT4_DISTINFO_FILE=	${.CURDIR}/../../devel/py-qt4/distinfo
QSCI2_DISTNAME=		QScintilla-gpl-${QSCI2_VERSION}
QSCI2_DISTINFO_FILE=	${.CURDIR}/../../devel/qscintilla2/distinfo
