# Created by: gahr
# $FreeBSD$

MASTERDIR=	${.CURDIR}/../qt4-qtsolutions-singleapplication

.include	"${MASTERDIR}/Makefile"

USE_QT4=	qmake_build moc_build rcc_build uic_build network xml gui

PORTNAME=	qt4-qtsolutions-soap

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	QT4 Solutions SOAP Component

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
