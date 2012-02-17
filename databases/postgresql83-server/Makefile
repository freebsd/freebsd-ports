# New ports collection makefile for:	PostgreSQL
# Date created:		November 13, 1998
# Whom:			Marc G. Fournier <scrappy@FreeBSD.org>
#
# $FreeBSD$
#

DISTVERSION?=	8.3.17
PORTREVISION?=	0
PKGNAMESUFFIX?=	-server

MAINTAINER?=	crees@FreeBSD.org

CONFIGURE_ARGS+=--with-docdir=${DOCSDIR}

ICU_PATCHFILE=	pg-8311-icu-xx-2010-05-14.diff.gz
BUILD_DIRS?=	src/port src/timezone src/backend \
		src/backend/utils/mb/conversion_procs src/backend/snowball \
		src/bin/initdb src/bin/ipcclean src/bin/pg_ctl \
		src/bin/pg_controldata src/bin/pg_resetxlog src/pl

.if defined(CLIENT_ONLY)
MAN1=		ipcclean.1
MAN7=		alter_operator_family.7 alter_text_search_configuration.7 \
		alter_text_search_dictionary.7 alter_text_search_parser.7 \
		alter_text_search_template.7 alter_view.7		  \
		create_operator_family.7 discard.7 drop_operator_family.7 \
		create_text_search_configuration.7			  \
		create_text_search_dictionary.7				  \
		create_text_search_parser.7				  \
		create_text_search_template.7				  \
		drop_text_search_configuration.7			  \
		drop_text_search_dictionary.7				  \
		drop_text_search_parser.7				  \
		drop_text_search_template.7
.endif

.if !defined(NO_BUILD)
pre-build:
	@ cd ${WRKSRC}/src/backend ;\
	    ${GMAKE} ../../src/include/parser/parse.h \
		     ../../src/include/utils/fmgroids.h
.endif

.include "${.CURDIR}/../postgresql84-server/Makefile"
