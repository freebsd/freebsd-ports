# Ports collection makefile for:	erlang-doc
# Date created:				31 Mar 2002
# Whom:					olgeni@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	erlang-doc
PORTVERSION=	r10b7
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	lang
MASTER_SITES=	http://www.erlang.se/doc/doc-5.4.9/pdf/:doc549 \
		http://erlang.org/download/:erlangorg \
		http://www.erlang.se/doc/:erlangse \
		http://www.sics.se/~joe/thesis/:joe \
		http://www.st.se/telecom/eng/projects/:stse
DISTFILES=	appmon-2.1.5.pdf:doc549 \
		asn1-1.4.4.7.pdf:doc549 \
		compiler-4.3.9.pdf:doc549 \
		cosEvent-2.1.pdf:doc549 \
		cosEventDomain-1.1.pdf:doc549 \
		cosFileTransfer-1.1.2.pdf:doc549 \
		cosNotification-1.1.1.pdf:doc549 \
		cosProperty-1.1.1.pdf:doc549 \
		cosTime-1.1.pdf:doc549 \
		cosTransactions-1.2.pdf:doc549 \
		crypto-1.3.pdf:doc549 \
		debugger-2.3.3.pdf:doc549 \
		design_principles-5.4.9.pdf:doc549 \
		efficiency_guide-5.4.9.pdf:doc549 \
		embedded-5.4.9.pdf:doc549 \
		erl_interface-3.5.4.pdf:doc549 \
		erts-5.4.9.pdf:doc549 \
		et-1.0.pdf:doc549 \
		getting_started-5.4.9.pdf:doc549 \
		gs-1.5.4.pdf:doc549 \
		ic-4.2.9.pdf:doc549 \
		inets-4.5.3.pdf:doc549 \
		installation_guide-5.4.9.pdf:doc549 \
		jinterface-1.3.pdf:doc549 \
		kernel-2.10.10.pdf:doc549 \
		megaco-3.0.1.pdf:doc549 \
		mnemosyne-1.2.5.pdf:doc549 \
		mnesia-4.2.2.pdf:doc549 \
		mnesia_session-1.1.5.pdf:doc549 \
		oam-5.4.9.pdf:doc549 \
		observer-0.9.6.2.pdf:doc549 \
		odbc-2.0.4.pdf:doc549 \
		orber-3.6.2.pdf:doc549 \
		os_mon-1.7.4.pdf:doc549 \
		otp_mibs-1.0.4.pdf:doc549 \
		parsetools-1.3.2.pdf:doc549 \
		pman-2.5.2.pdf:doc549 \
		programming_examples-5.4.9.pdf:doc549 \
		reference_manual-5.4.9.pdf:doc549 \
		runtime_tools-1.5.1.1.pdf:doc549 \
		sasl-2.0.1.pdf:doc549 \
		snmp-4.3.pdf:doc549 \
		ssl-3.0.7.pdf:doc549 \
		stdlib-1.13.9.pdf:doc549 \
		system_architecture_intro-5.4.9.pdf:doc549 \
		system_principles-5.4.9.pdf:doc549 \
		toolbar-1.2.1.pdf:doc549 \
		tools-2.4.5.pdf:doc549 \
		tutorial-5.4.9.pdf:doc549 \
		tv-2.1.2.pdf:doc549 \
		webtool-0.8.2.pdf:doc549 \
		xmerl-1.0.3.pdf:doc549 \
		course.pdf:erlangorg \
		erlang-book-part1.pdf:erlangorg \
		programming_rules.pdf:erlangse \
		armstrong_thesis_2003.pdf:joe \
		master_thesis_patterns.pdf:stse
DIST_SUBDIR=	erlang
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
