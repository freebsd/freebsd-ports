# Created by: gahr
# $FreeBSD$

MASTERDIR=	${.CURDIR}/../qt4-qtsolutions-singleapplication

USES=	qt:4
USE_QT=		qmake_build moc_build rcc_build uic_build network xml gui

.include	"${MASTERDIR}/Makefile"

PORTNAME=	qt4-qtsolutions-soap

MAINTAINER=	ports@FreeBSD.org
COMMENT=	QT4 Solutions SOAP Component

DEPRECATED=		Qt4 has been EOL since december 2015
EXPIRATION_DATE=	2019-03-15

DESCR=		${.CURDIR}/pkg-descr

PATCHDIR=	${.CURDIR}/files

SUB_PROJECT_NAME=	qtsoap
LIBRARY_NAME=		libQtSolutions_SOAP-head.so
LIBRARY_HEADERS=	qtsoap.h \
			QtSoapArray \
			QtSoapArrayIterator \
			QtSoapHttpTransport \
			QtSoapMessage \
			QtSoapNamespaces \
			QtSoapQName \
			QtSoapSimpleType \
			QtSoapStruct \
			QtSoapStructIterator \
			QtSoapType \
			QtSoapTypeConstructor \
			QtSoapTypeConstructorBase \
			QtSoapTypeFactory
