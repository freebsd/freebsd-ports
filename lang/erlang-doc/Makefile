# Ports collection makefile for:	erlang-doc
# Date created:				31 Mar 2002
# Whom:					olgeni@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	erlang-doc
PORTVERSION=	9.0
PORTREVISION=	2
CATEGORIES=	lang
MASTER_SITES=	http://www.erlang.org/doc/r9b/pdf/ \
		http://erlang.org/download/
DISTFILES=      appmon-2.1.1.pdf \
		asn1-1.4.pdf \
		compiler-4.1.pdf \
		cosEvent-2.0.pdf \
		cosEventDomain-1.0.pdf \
		cosFileTransfer-1.0.2.pdf \
		cosNotification-1.0.6.pdf \
		cosProperty-1.0.1.pdf \
		cosTime-1.0.1.1.pdf \
		cosTransactions-1.1.2.pdf \
		crypto-1.1.2.pdf \
		debugger-2.1.pdf \
		design_principles-5.2.pdf \
		efficiency_guide-5.2.pdf \
		embedded-5.2.pdf \
		erl_interface-3.3.2.pdf \
		erts-5.2.pdf \
		et-1.0.pdf \
		eva-2.0.3.pdf \
		extensions-5.2.pdf \
		getting_started-5.2.pdf \
		gs-1.5.0.pdf \
		ic-4.1.6.pdf \
		inets-3.0.pdf \
		installation_guide-5.2.pdf \
		jinterface-1.2.1.pdf \
		kernel-2.8.0.pdf \
		megaco-1.1.0.pdf \
		mnemosyne-1.2.5.pdf \
		mnesia-4.1.pdf \
		mnesia_session-1.1.5.pdf \
		oam-5.2.pdf \
		observer-0.9.pdf \
		odbc-1.0.pdf \
		orber-3.3.pdf \
		os_mon-1.6.0.pdf \
		parsetools-1.2.pdf \
		pman-2.4.1.pdf \
		runtime_tools-1.3.pdf \
		sasl-1.9.4.pdf \
		snmp-3.3.8.pdf \
		ssl-2.3.5.pdf \
		stdlib-1.11.0.pdf \
		system_architecture_intro-5.2.pdf \
		system_principles-5.2.pdf \
		toolbar-1.1.0.pdf \
		tools-2.1.pdf \
		tutorial-5.2.pdf \
		tv-2.0.4.pdf \
		webtool-0.7.1.pdf \
		course.pdf

DIST_SUBDIR=	erlang
EXTRACT_ONLY=

MAINTAINER=	olgeni@FreeBSD.org

NO_BUILD=	yes

do-install:
	@${MKDIR} ${LOCALBASE}/share/doc/erlang
.for FILE in ${DISTFILES}
	@${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/${FILE} ${LOCALBASE}/share/doc/erlang
.endfor

.include <bsd.port.mk>
