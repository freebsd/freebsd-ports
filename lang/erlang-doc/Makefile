# Ports collection makefile for:	erlang-doc
# Date created:				31 Mar 2002
# Whom:					olgeni@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	erlang-doc
PORTVERSION=	r10b2
PORTEPOCH=	1
CATEGORIES=	lang
MASTER_SITES=	http://www.erlang.se/doc/doc-5.4.3/pdf/ \
		http://erlang.org/download/ \
		http://www.erlang.se/doc/ \
		http://www.sics.se/~joe/thesis/ \
		http://www.st.se/telecom/eng/projects/
DISTFILES=	appmon-2.1.3.pdf \
		asn1-1.4.4.4.pdf \
		compiler-4.3.2.pdf \
		cosEvent-2.1.pdf \
		cosEventDomain-1.1.pdf \
		cosFileTransfer-1.1.2.pdf \
		cosNotification-1.1.1.pdf \
		cosProperty-1.1.1.pdf \
		cosTime-1.1.pdf \
		cosTransactions-1.2.pdf \
		crypto-1.2.2.pdf \
		debugger-2.3.1.pdf \
		design_principles-5.4.3.pdf \
		efficiency_guide-5.4.3.pdf \
		embedded-5.4.3.pdf \
		erl_interface-3.5.pdf \
		erts-5.4.3.pdf \
		et-1.0.pdf \
		getting_started-5.4.3.pdf \
		gs-1.5.3.pdf \
		ic-4.2.7.pdf \
		inets-4.0.1.pdf \
		installation_guide-5.4.3.pdf \
		jinterface-1.3.pdf \
		kernel-2.10.3.pdf \
		megaco-2.1.7.pdf \
		mnemosyne-1.2.5.pdf \
		mnesia-4.2.pdf \
		mnesia_session-1.1.5.pdf \
		oam-5.4.3.pdf \
		observer-0.9.6.pdf \
		odbc-2.0.2.pdf \
		orber-3.5.3.pdf \
		os_mon-1.7.1.pdf \
		otp_mibs-1.0.4.pdf \
		parsetools-1.3.pdf \
		pman-2.5.1.pdf \
		programming_examples-5.4.3.pdf \
		reference_manual-5.4.3.pdf \
		runtime_tools-1.5.pdf \
		sasl-2.0.pdf \
		snmp-4.0.4.pdf \
		ssl-3.0.4.pdf \
		stdlib-1.13.3.pdf \
		system_architecture_intro-5.4.3.pdf \
		system_principles-5.4.3.pdf \
		toolbar-1.2.pdf \
		tools-2.4.pdf \
		tutorial-5.4.3.pdf \
		tv-2.1.1.pdf \
		webtool-0.8.2.pdf \
		xmerl-1.0.pdf \
		course.pdf \
		erlang-book-part1.pdf \
		programming_rules.pdf \
		armstrong_thesis_2003.pdf \
		master_thesis_patterns.pdf
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

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
