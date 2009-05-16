--
-- Execute the following SQL statements to enable PL/Ruby.
--
-- $FreeBSD$
--

CREATE FUNCTION plruby_call_handler() RETURNS language_handler
	AS '!!PLRUBY_SO!!'
	LANGUAGE 'C';

CREATE TRUSTED LANGUAGE 'plruby'
	HANDLER plruby_call_handler
	LANCOMPILER 'PL/Ruby';

--
