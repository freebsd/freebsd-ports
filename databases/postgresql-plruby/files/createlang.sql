--
-- Execute the following SQL statements to enable PL/Ruby.
--
-- $FreeBSD$
--

CREATE FUNCTION plruby_call_handler() RETURNS OPAQUE
	AS '!!PLRUBY_SO!!'
	LANGUAGE 'C';

CREATE TRUSTED PROCEDURAL LANGUAGE 'plruby'
	HANDLER plruby_call_handler
	LANCOMPILER 'PL/Ruby';

--
