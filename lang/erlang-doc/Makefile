# Ports collection makefile for:	erlang-doc
# Date created:				31 Mar 2002
# Whom:					olgeni@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	erlang-doc
PORTVERSION=	r9c
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	lang
MASTER_SITES=	http://www.erlang.org/doc/r9c/pdf/ \
		http://erlang.org/download/ \
		http://www.erlang.se/doc/
DISTFILES=	appmon-2.1.2.pdf \
		asn1-1.4.2.pdf \
		compiler-4.2.pdf \
		cosEvent-2.1.pdf \
		cosEventDomain-1.1.pdf \
		cosFileTransfer-1.1.pdf \
		cosNotification-1.1.pdf \
		cosProperty-1.1.pdf \
		cosTime-1.1.pdf \
		cosTransactions-1.2.pdf \
		crypto-1.2.pdf \
		debugger-2.2.pdf \
		design_principles-5.3.pdf \
		efficiency_guide-5.3.pdf \
		embedded-5.3.pdf \
		erl_interface-3.4.pdf \
		erts-5.3.pdf \
		et-1.0.pdf \
		eva-2.0.4.pdf \
		getting_started-5.3.pdf \
		gs-1.5.2.pdf \
		ic-4.2.1.pdf \
		inets-3.0.6.pdf \
		installation_guide-5.3.pdf \
		jinterface-1.2.1.1.pdf \
		kernel-2.9.pdf \
		megaco-1.2.3.pdf \
		mnemosyne-1.2.5.pdf \
		mnesia-4.1.4.pdf \
		mnesia_session-1.1.5.pdf \
		oam-5.3.pdf \
		observer-0.9.5.pdf \
		odbc-1.0.8.pdf \
		orber-3.4.2.pdf \
		os_mon-1.6.1.pdf \
		otp_mibs-1.0.pdf \
		parsetools-1.2.pdf \
		pman-2.4.1.pdf \
		programming_examples-5.3.pdf \
		reference_manual-5.3.pdf \
		runtime_tools-1.4.pdf \
		sasl-1.10.pdf \
		snmp-3.4.pdf \
		ssl-3.0.1.pdf \
		stdlib-1.12.pdf \
		system_architecture_intro-5.3.pdf \
		system_principles-5.3.pdf \
		toolbar-1.1.0.pdf \
		tools-2.3.pdf \
		tutorial-5.3.pdf \
		tv-2.0.5.pdf \
		webtool-0.8.1.pdf \
		course.pdf \
		erlang-book-part1.pdf \
		programming_rules.pdf

DIST_SUBDIR=	erlang
EXTRACT_ONLY=

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Documentation (PDF) for the Erlang/OTP system

NO_BUILD=	yes

do-install:
	@${MKDIR} ${LOCALBASE}/share/doc/erlang
.for FILE in ${DISTFILES}
	@${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/${FILE} ${LOCALBASE}/share/doc/erlang
.endfor

.include <bsd.port.mk>
