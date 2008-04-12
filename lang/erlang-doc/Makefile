# Ports collection makefile for:	erlang-doc
# Date created:				31 Mar 2002
# Whom:					olgeni@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	erlang-doc
PORTVERSION=	r12b2
PORTEPOCH=	1
CATEGORIES=	lang
MASTER_SITES=	http://www.erlang.org/documentation/doc-5.6.2/pdf/:release \
		http://erlang.org/download/:erlangorg \
		http://www.erlang.se/doc/:erlangse \
		http://www.sics.se/~joe/thesis/:joe \
		http://www.st.se/telecom/eng/projects/:stse \
		${MASTER_SITE_LOCAL:S/$/:local/}
MASTER_SITE_SUBDIR=     olgeni/:local
DISTFILES=	appmon-2.1.9.pdf:release \
		asn1-1.5.1.pdf:release \
		common_test-1.3.1.pdf:release \
		compiler-4.5.2.pdf:release \
		cosEvent-2.1.3.pdf:release \
		cosEventDomain-1.1.3.pdf:release \
		cosFileTransfer-1.1.5.pdf:release \
		cosNotification-1.1.7.pdf:release \
		cosProperty-1.1.6.pdf:release \
		cosTime-1.1.3.pdf:release \
		cosTransactions-1.2.4.pdf:release \
		crypto-1.5.1.1.pdf:release \
		debugger-3.1.1.2.pdf:release \
		design_principles-5.6.2.pdf:release \
		dialyzer-1.8.0.pdf:release \
		docbuilder-0.9.8.4.pdf:release \
		edoc-0.7.5.pdf:release \
		efficiency_guide-5.6.2.pdf:release \
		embedded-5.6.2.pdf:release \
		erl_interface-3.5.6.pdf:release \
		erts-5.6.2.pdf:release \
		et-1.3.pdf:release \
		getting_started-5.6.2.pdf:release \
		gs-1.5.9.pdf:release \
		ic-4.2.17.pdf:release \
		inets-5.0.5.pdf:release \
		installation_guide-5.6.2.pdf:release \
		inviso-0.6.pdf:release \
		jinterface-1.4.pdf:release \
		kernel-2.12.2.pdf:release \
		megaco-3.7.4.pdf:release \
		mnesia-4.4.2.pdf:release \
		oam-5.6.2.pdf:release \
		observer-0.9.7.4.pdf:release \
		odbc-2.10.pdf:release \
		orber-3.6.9.pdf:release \
		os_mon-2.1.5.pdf:release \
		otp_mibs-1.0.4.1.pdf:release \
		parsetools-1.4.4.pdf:release \
		percept-0.7.1.pdf:release \
		pman-2.6.pdf:release \
		programming_examples-5.6.2.pdf:release \
		reference_manual-5.6.2.pdf:release \
		runtime_tools-1.7.2.pdf:release \
		sasl-2.1.5.2.pdf:release \
		snmp-4.10.3.pdf:release \
		ssh-0.9.9.6.pdf:release \
		ssl-3.9.pdf:release \
		stdlib-1.15.2.pdf:release \
		syntax_tools-1.5.4.pdf:release \
		system_architecture_intro-5.6.2.pdf:release \
		system_principles-5.6.2.pdf:release \
		test_server-3.2.2.pdf:release \
		toolbar-1.3.0.1.pdf:release \
		tools-2.6.1.pdf:release \
		tutorial-5.6.2.pdf:release \
		tv-2.1.4.2.pdf:release \
		webtool-0.8.3.2.pdf:release \
		xmerl-1.1.8.pdf:release \
		course.pdf:erlangorg \
		erlang-book-part1.pdf:erlangorg \
		programming_rules.pdf:erlangse \
		armstrong_thesis_2003.pdf:joe \
		master_thesis_patterns.pdf:local
DIST_SUBDIR=	${PORTNAME}/${PORTVERSION}
EXTRACT_ONLY=

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Documentation (PDF) for the Erlang/OTP system

NO_BUILD=	yes

do-install:
	@${MKDIR} ${LOCALBASE}/share/doc/erlang
.for FILE in ${DISTFILES}
	@${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/$$(expr ${FILE} : '\([^:]*\)') ${LOCALBASE}/share/doc/erlang
.endfor

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
